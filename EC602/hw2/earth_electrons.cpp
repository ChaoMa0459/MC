// Copyright 2017 Chao Ma mc163@bu.edu
#include <iostream>
#include <math.h>

using namespace std;

int main(){
	double mass_earth = 5.972 * pow(10, 24);
	double mass_proton = 1.6726 * pow(10, -27);
	double hydrogen_relative_atomic_mass = 1;
	double hydrogen_electrons = 1;
	double oxygen_relative_atomic_mass = 16;
	double oxygen_electrons = 8;
	double average_electrons;
	double lower_electrons;
	double upper_electrons;
	double terabyte = pow(1024, 4) * 8;

	// all O
	lower_electrons = mass_earth / mass_proton * oxygen_electrons / oxygen_relative_atomic_mass;
	// all H 
	upper_electrons = mass_earth / mass_proton * hydrogen_electrons / hydrogen_relative_atomic_mass;
	// half O, half H
	average_electrons = (lower_electrons + upper_electrons) / 2;

	cout << average_electrons / terabyte << endl;
	cout << lower_electrons / terabyte << endl;
	cout << upper_electrons / terabyte << endl;
	return 0;
}
