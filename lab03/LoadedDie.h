#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Die.h" // changed

#pragma once
using namespace std;

class LoadedDie: public Die   // changed
	{
		//int loaded_sides; // changed
	public:
                LoadedDie(int); // added
		void set_sides(int);
		int die_roll(); // changed
	};


