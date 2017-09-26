// Copyright 2017 Chao Ma mc163@bu.edu
#include <iostream>
#include <stdint.h>
#include <cfloat>
#include <math.h>

int main(){
	double Rs16 = 0.0, Ri16 = 0.0 ,Rm16 = 0.0;
	//pow(2, -14)
	double smallest_float_greater_than_zero16 = 6.10352 * pow(10, -5);
	double maximum_float_value16 = 65504;
	int16_t maximum_int_value16 = 32767;
	//2^11
	double N16 = 2048;
	
	double Rs32 = 0.0, Ri32 = 0.0 ,Rm32 = 0.0;
	//2^-126
//	double smallest_float_greater_than_zero32 = 1.175494351 e−38;
	double smallest_float_greater_than_zero32 = 1.175494351 * pow(10, -38);
	double maximum_float_value32 = 3.402823 * pow(10, 38);
	int32_t maximum_int_value32 = 2147483647;
	//2^24
	double N32 = 16777216;

	double Rs64 = 0.0, Ri64 = 0.0 ,Rm64 = 0.0;
	//2^-1022
//	double smallest_float_greater_than_zero64 = 2.2250738585072009e−308;
	double smallest_float_greater_than_zero64 = 2.2250738585072009 * pow(10, -308);
	double maximum_float_value64 = 1.7976931348623157 * pow(10, 308);
	int64_t maximum_int_value64 = 9223372036854775807;
	//2^53
	double N64 = 9.007199255e15;

	Ri16 =  maximum_int_value16 / N16;
	Rm16 = maximum_float_value16 / maximum_int_value16;
	Rs16 = 1 / smallest_float_greater_than_zero16;

	Ri32 =  maximum_int_value32 / N32;
	Rm32 = maximum_float_value32 / maximum_int_value32;
	Rs32 = 1 / smallest_float_greater_than_zero32;

	Ri64 =  maximum_int_value64 / N64;
	Rm64 = maximum_float_value64 / maximum_int_value64;
	Rs64 = 1 / smallest_float_greater_than_zero64;

  // calculate Rs, Ri, and Rm for half/binary16 vs int16_t
  std::cout<< "16 : Ri= " << Ri16 << " Rm= " << Rm16 << " Rs= " << Rs16 << std::endl;
  // calculate Rs, Ri, and Rm for float/single/binary32 vs int32_t
  std::cout<< "32 : Ri= " << Ri32 << " Rm= " << Rm32 << " Rs= " << Rs32 << std::endl;
  // calculate Rs, Ri, and Rm for double/binary64 vs int64_t
  std::cout<< "64 : Ri= " << Ri64 << " Rm= " << Rm64 << " Rs= " << Rs64 << std::endl;
  return 0;
}
