#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "LoadedDie.h"  // changed


LoadedDie::LoadedDie(int y) : Die(y) // added constructor
{
}

void LoadedDie::set_sides(int y)   // changed
{
	num_sides = y;  // changed
	cout<<"there are this many sides on the die "<< num_sides<<endl; // changed

}


int LoadedDie::die_roll()    // changed
{
	if (rand() % 2 ==0)
		{	
			int t =0;
			t=rand() % 4 + 3;
			cout<<"the loaded roll was "<< t <<endl;
			return t;
			
			

		 	
		}
	
	else{
			int h=0;
			h=rand() % num_sides + 1; // changed loaded_sides
                                                  // to num_sides
			cout<<"the loaded roll was "<<h<<endl;
			return h;
		}
}
