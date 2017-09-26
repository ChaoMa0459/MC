// Copyright 2017 Chao Ma mc163@bu.edu
#include <iostream>
#include <ctime>
#include <stdint.h>
#include <math.h>

using namespace std;

int main()
{	
	clock_t start_clock,end_clock;
	start_clock = clock();  // Timing starts here
	uint16_t m = 1;
	while (m > 0) 
	{
		 m++;
	}
	end_clock = clock();    // Timing stops here
	long double sec16 = (long double)(end_clock-start_clock) / CLOCKS_PER_SEC;
	long double sec8 = sec16 / pow(2, 8);
	long double sec32 = sec16 * pow(2, 16);
	long double sec64 = sec16 * pow(2, 48);
//    cout << "counting to one billion took " << sec16 << " seconds" << endl;

  cout << "estimated int8 time (nanoseconds): "
            << 1000000000 * sec8 << endl;
  cout << "measured int16 time (microseconds): "
            << 1000000 * sec16 << endl;
  cout << "estimated int32 time (seconds): "
            << sec32 << endl;
  cout << "estimated int64 time (years): "
            << sec64 / (3600 * 24 * 365) << endl;
}
