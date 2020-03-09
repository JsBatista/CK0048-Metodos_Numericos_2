#pragma once

#include "Answer.h"

class Derivatives
{
	public:
		Derivatives();
		Answer calculate_forward( double (*f)(double), double x, double delta_x);
		Answer calculate_backwards( double (*f)(double), double x, double delta_x);
		Answer calculate_central( double (*f)(double), double x, double delta_x);


		Answer calculate_second_forward( double (*f)(double), double x, double delta_x);
		Answer calculate_second_backwards( double (*f)(double), double x, double delta_x);
		Answer calculate_second_central( double (*f)(double), double x, double delta_x);
};