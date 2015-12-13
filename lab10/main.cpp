/*********************************************************************
 ** Program Filename: main.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 11/30/15
 ** Description: The program compares the run times for different
 **              implementations of factorial and Fibonacci
 **              functions.
 ** Input: n/a
 ** Output: std::cout, run times for each function
 *********************************************************************/


#include <chrono>
#include <ctime>
#include <iostream>


// alias
typedef unsigned long long int ullint;

// forward declarations

// single recursion
ullint factorial_sr(ullint n);

// tail recursion
ullint factorial_tr(ullint n);
// helper:
ullint factorial_tr_helper(ullint n, ullint result);

// iterative
ullint fibonacci_i(ullint n);

// double recursion
ullint fibonacci_r(ullint n);


// function pointer alias
typedef ullint (*fcn)(ullint);


long time_function(ullint input, unsigned int num_tests, fcn f);


int main()
{
    typedef unsigned long long int ullint;

    const int TESTS = 100000;   // tests to run for each function
    const int FACT_N = 20;      // input to factorial
    const int FIB_N = 20;       // input to Fibonacci

    // test factorial using single recursion
    std::cout << FACT_N << "! = " << factorial_sr(FACT_N) << '\n';
    
    std::cout << "Time to find " << FACT_N << "! using single recursion "
              << TESTS << " times: "
              << time_function(FACT_N, TESTS, factorial_sr)
              << " seconds\n\n";

    // test factorial using tail recursion
    std::cout << FACT_N << "! = " << factorial_tr(FACT_N) << '\n';
    
    std::cout << "Time to find " << FACT_N << "! using tail recursion "
              << TESTS << " times: "
              << time_function(FACT_N, TESTS, factorial_tr)
              << " seconds\n\n";

    // test Fibonacci using iteration
    std::cout << "fib(" << FIB_N << ") = " << fibonacci_i(FIB_N) << '\n';
    
    std::cout << "Time to find fib(" << FIB_N
              << ") using iteration "
              << TESTS << " times: "
              << time_function(FIB_N, TESTS, fibonacci_i)
              << " seconds\n\n";

    // test Fibonacci using double recursion
    std::cout << "fib(" << FIB_N << ") = " << fibonacci_r(FIB_N) << '\n';
    
    std::cout << "Time to find fib(" << FIB_N
              << ") using double recursion "
              << TESTS << " times: "
              << time_function(FIB_N, TESTS, fibonacci_r)
              << " seconds\n\n";

    return 0;
}


/*********************************************************************
 ** Function: fibonacci_i()
 ** Description: Returns the nth Fibonacci number.  Uses iteration.
 *********************************************************************/

ullint fibonacci_i(ullint n)
{
    ullint f_1 = 1;     // f(i - 1)
    ullint f_2 = 0;     // f(i - 2)

    for (ullint i = 2ULL; i <= n; ++i)
    {
        // temp variable to store current Fibonacci number
        ullint sum = f_1 + f_2;

        // update the previous two Fibonacci numbers for next iteration
        f_2 = f_1;
        f_1 = sum;
    }

    // stores the Fibonacci number we want now
    return f_1;
}


/*********************************************************************
 ** Function: fibonacci_r()
 ** Description: Returns the nth Fibonacci number.  Uses double
 **              recursion.
 *********************************************************************/

ullint fibonacci_r(ullint n)
{
    // base cases
    if (n == 0ULL || n == 1ULL) return n;

    return fibonacci_r(n - 1) + fibonacci_r(n - 2);
}


/*********************************************************************
 ** Function: factorial_sr()
 ** Description: Calculates n! using single recursion and returns it.
 *********************************************************************/

ullint factorial_sr(ullint n)
{
    // base case
    if (n == 0ULL) return 1ULL;

    return factorial_sr(n - 1ULL) * n;
}


/*********************************************************************
 ** Function: factorial_tr()
 ** Description: Calculates n! using tail recursion and returns it.
 *********************************************************************/

ullint factorial_tr(ullint n)
{
    return factorial_tr_helper(n, 1ULL);
}


/*********************************************************************
 ** Function: factorial_tr_helper()
 ** Description: Helper function for factorial_tr().
 *********************************************************************/

ullint factorial_tr_helper(ullint n, ullint result)
{
    // base case
    if (n == 0ULL) return result;

    return factorial_tr_helper(n - 1ULL, result * n);
}


/*********************************************************************
 ** Function: time_function()
 ** Description: Returns the time needed to get the result of a
 **              function taking and returning an unsigned long long
 **              value num_tests times.
 ** Parameters: input       input to f
 **             num_tests   number of runs
 **             f           function to test
 *********************************************************************/

long time_function(ullint input, unsigned int num_tests, fcn f)
{
    time_t start = time(0U);

    // call the function with the specified input num_tests times
    for (unsigned int i = 0; i < num_tests; ++i)
        f(input);

    time_t end = time(0U);

    return end - start;
}
