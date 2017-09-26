// Copyright 2017 Chao Ma mc163@bu.edu

// v[0] + v[1] * x^1 + ⋯  + v[N−2] * x^(N−2) + v[N−1] * x^(N−1) 

//#include <iostream>
#include <vector>

using namespace std;

typedef vector<double> Poly;

// Add two polynomials, returning the result
Poly add_poly(const Poly &a,const Poly &b);

// Multiply two polynomials, returning the result.
Poly multiply_poly(const Poly &a,const Poly &b);

Poly add_poly(const Poly &a, const Poly &b){
	// find the max size of a and b
	int size_max = a.size() > b.size() ? a.size() : b.size();
	Poly c(size_max, 0);
	for (int i = 0; i < size_max; i++){
		c[i] = a[i] + b[i];
	}
	// remove the additional 0s
	for (int i = size_max - 1; i > 0; i--){
		if (c[i] == 0){
			c.pop_back();
		} else {
			break;
		}
	}
	return c;
}

Poly multiply_poly(const Poly &a,const Poly &b){
	// the max size of muliplied result
	int size_max = a.size() + b.size() - 1;
	Poly c(size_max, 0);
	for (int i = 0; i < a.size(); i++){
		for (int j = 0; j < b.size(); j++){
			c[i + j] += a[i] * b[j];
		}
	}
	// remove the additional 0s
	for (int i = size_max - 1; i > 0; i--){
		if (c[i] == 0){
			c.pop_back();
		} else {
			break;
		}
	}
	return c;
}
