// Copyright 2017 Chao Ma mc163@bu.edu 

//#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef string BigInt;
typedef vector<double> Poly;
BigInt multiply_int(const BigInt &a,const BigInt &b);
Poly multiply_poly(const Poly &a,const Poly &b);
Poly to_Poly(const BigInt &a);
BigInt to_BigInt(const Poly &a);
Poly carry(const Poly &a);

/*
int main() { 
  BigInt A,B;
  cin >> A >> B;
  cout << multiply_int(A,B) << endl;
}
*/

BigInt multiply_int(const BigInt &a,const BigInt &b) {
	Poly A;
	A = multiply_poly(to_Poly(a), to_Poly(b));

//	for (int i = 0; i < A.size(); i++)
//		cout << A[i] << ' ';
//	cout << endl;

	A = carry(A);
	return to_BigInt(A);	
}

Poly carry(const Poly &a){
	Poly result = a;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] >= 10) {
			// add one more bit
			if (i == a.size() - 1){
				result.push_back((int)result[i] / 10);
			} else {
			// carry into higher bit
				result[i + 1] += (int)result[i] / 10;
			}
		}
		result[i] = (int)result[i] % 10;
	}
	return result;
}

Poly to_Poly(const BigInt &a) {
	Poly A(a.size(), 0);
	// reverse order
	for (int i = 0; i < a.size(); i++) {
		A[i] = a[a.size() - i - 1] - '0';
	}
	return A;
}

BigInt to_BigInt(const Poly &a) {
	BigInt A(a.size(), 0);
	// reverse order back
	for (int i = 0; i < a.size(); i++) {
		A[i] = a[a.size() -i - 1] + '0';
	}
	return A;
}

// Multiply two polynomials, returning the result.
Poly multiply_poly(const Poly &a,const Poly &b) {
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

