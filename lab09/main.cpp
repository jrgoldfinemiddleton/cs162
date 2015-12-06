/*********************************************************************
 ** Program Filename: main.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 11/19/15
 ** Description: This program simulates a mess hall that increasingly
 **              gets busier and then increasingly slower.  The goal is
 **              to compare the average time a diner waits in line
 **              to be served under each of two scenarios: A) there is
 **              a single line and n servers and B) there are n lines
 **              and n servers.
 ** Input: std::cin, number of servers n
 ** Output: std::cout, average wait time - measured in people served
 **                    by the same server while a particular person
 **                    waits in line
 *********************************************************************/


#include "utilities.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <queue>
#include <vector>


long distribute(std::vector<std::queue<long> >& lines, long arrivals);
long get_max_queue_length(std::vector<std::queue<long> >& lines);
long get_total_wait(std::vector<std::queue<long> >& lines, long arrivals);
double run_simulation_multi(int n);
double run_simulation_single(int n);
void serve(std::vector<std::queue<long> >& lines);


int main()
{
    srand(static_cast<unsigned int>(time(0)));

    // play again?
    bool again = true;

    while (again)
    {
        std::cout << "Welcome to the Queue Analyzer.\n\n";

        std::cout << "How many servers are there? ";
        int servers = utilities::get_valid_int_in_range(1, 100);
        
        std::cout << "\nRunning the simulation with " << servers <<
                     " servers and 1 queue.\n";

        // run simulation with 1 queue
        double avg_wait = run_simulation_single(servers);
        std::cout << "Average wait: " << avg_wait << " ticks\n";

        
        std::cout << "\nRunning the simulation with " << servers <<
                     " servers and " << servers << " queues.\n";

        // run simulation with multiple queues
        avg_wait = run_simulation_multi(servers);
        std::cout << "Average wait: " << avg_wait << " ticks\n";

        char c;
        std::cout << "\nPlay again (y/n)? ";
        std::cin >> c;
        again = (c == 'y' || c == 'Y') ? true : false;
    }

    return 0;
}


/*********************************************************************
 ** Function: distribute()
 ** Description: Distributes a number of people into separate queues
 **              relatively evenly, returning the cumulative wait time
 **              for all new arrivals to the queues.
 ** Parameters: lines       vector of queues to store arrivals
 **             arrivals    number of people to distribute into queues
 ** Pre-Conditions: lines contains at least one queue, arrivals > 0
 ** Post-Conditions: arrivals people will be distributed into the
 **                  queues in lines
 *********************************************************************/

long distribute(std::vector<std::queue<long> >& lines, long arrivals)
{
    // total ticks to be waited by the arrivals
    long total_wait = 0;

    long num_lines = lines.size();

    // for all arrivals
    for (long i = 0; i < arrivals; ++i)
    {
        // wrap around if more arrivals than lines
        long cur_line = i % num_lines;

        // total wait increased by number in current queue
        total_wait += lines[cur_line].size();

        lines[cur_line].push(i);
    }

    return total_wait;
}


/*********************************************************************
 ** Function: get_max_queue_length()
 ** Description: Returns the length of the longest queue contained in
 **              lines.
 ** Parameters: lines   the vector containing queues of people
 ** Pre-Conditions: lines contains at least one queue
 ** Post-Conditions: the length of the longest queue is returned
 *********************************************************************/

long get_max_queue_length(std::vector<std::queue<long> >& lines)
{
    // accumulator
    long max = 0;

    long num_lines = lines.size();

    for (long line = 0; line < num_lines; ++line)
    {
        int sz = lines[line].size();
        if (sz > max)
            max = sz;
    }

    return max;
}


/*********************************************************************
 ** Function: get_total_wait()
 ** Description: Returns the cumulative wait time of all the people
 **              to be added to lines.
 ** Parameters: lines       vector of queues to store arrivals
 **             arrivals    number of people to distribute into queues
 ** Pre-Conditions: lines contains at least one queue, arrivals > 0
 ** Post-Conditions: arrivals people will be distributed into the
 **                  queues in lines
 *********************************************************************/

long get_total_wait(std::vector<std::queue<long> >& lines, long arrivals)
{
    return distribute(lines, arrivals);
}


/*********************************************************************
 ** Function: run_simulation_multi()
 ** Description: Runs a simulation with n lines and n servers.  Returns
 **              the average wait time, in ticks, per person to get
 **              served.
 ** Parameters: n   the number of servers and also the number of lines
 ** Pre-Conditions: n > 1
 ** Post-Conditions: the simulation is run and a double representing
 **                  average number of ticks per person is returned
 *********************************************************************/

double run_simulation_multi(int n)
{
    // collect the lines
    std::vector<std::queue<long> > lines;

    // create all lines
    for (int line_no = 0; line_no < n; ++line_no)
    {
        std::queue<long> q;
        lines.push_back(q);
    }

    // limit to arrivals
    const int arrival_cycles = 10;

    // keep track of cycle, also serves a multiplier
    int cycle = 1;

    // accumulators
    long total_arrivals = 0;
    long total_wait = 0;

    // true until arrivals start decreasing
    bool increasing = true;

    // run arrivals and services
    while (cycle >= 0)
    {
        // calculate number of arrivals
        int arrivals = (cycle == 1) ? n : cycle * n + rand() % n + 1;
        total_arrivals += arrivals;

        // add arrivals to queues and determine the total waiting time
        // for the new arrivals
        total_wait += get_total_wait(lines, arrivals);

        // remove a person from each queue
        serve(lines);

        // once the cycle reaches 10, signal to start going back down
        if (increasing)
        {
            if (++cycle == arrival_cycles) increasing = false;
        }
        else
            --cycle;
    }

    // clear out everyone else
    long remaining_ticks = get_max_queue_length(lines);
    while (remaining_ticks-- > 0)
        serve(lines);

    // return average wait time
    return static_cast<double>(total_wait) / total_arrivals;
}


/*********************************************************************
 ** Function: run_simulation_single()
 ** Description: Runs a simulation with 1 line and n servers.  Returns
 **              the average wait time, in ticks, per person to get
 **              served.
 ** Parameters: n   the number of servers
 ** Pre-Conditions: n > 1
 ** Post-Conditions: the simulation is run and a double representing
 **                  average number of ticks per person is returned
 *********************************************************************/

double run_simulation_single(int n)
{
    // line of diners
    std::queue<long> line;

    // limit to arrivals
    const int arrival_cycles = 10;

    // keep track of cycle, also serves as a multiplier
    int cycle = 1;

    // accumulators
    long total_arrivals = 0;
    long total_wait = 0;

    // wait time for new arrivals, in ticks
    long current_wait = 0;

    // true until arrivals start decreasing
    bool increasing = true;

    // run arrivals and services
    while (cycle >= 0)
    {
        // calculate number of arrivals
        int arrivals = (cycle == 1) ? n : cycle * n + rand() % n + 1;
        total_arrivals += arrivals;

        // add new arrivals to queue
        for (long i = 0; i < arrivals; ++i)
        {
            line.push(i);

            // each n arrivals increases wait time by 1 tick
            if (!(i % n) && i != 0)
                ++current_wait;

            total_wait += current_wait;
        }

        // remove one person per server
        for (long i = 0; i < n; ++i)
            line.pop();

        // wait for new arrivals down by 1 tick
        --current_wait;
        
        // once the cycle reaches 10, signal to start going back down
        if (increasing)
        {
            if (++cycle == arrival_cycles) increasing = false;
        }
        else
            --cycle;
    }

    // clear out everyone else
    long remaining_ticks = line.size();
    while (remaining_ticks-- > 0)
        line.pop();

    // return average wait time
    return static_cast<double>(total_wait) / total_arrivals;
}


/*********************************************************************
 ** Function: serve()
 ** Description: Removes a single waiting person from each line in
 **              lines, if there is one.
 ** Parameters: lines   vector of queues representing lines of people
 ** Pre-Conditions: lines contains at least one queue
 ** Post-Conditions: each non-empty queue's size is decremented
 *********************************************************************/

void serve(std::vector<std::queue<long> >& lines)
{
    long num_lines = lines.size();
    for (long line = 0; line < num_lines; ++line)
        lines[line].pop();
}
