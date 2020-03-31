#pragma once

#include "Answer.h"

class Integrate
{
	public:
		Integrate();
		Answer calculate_by_newton_cotes_deg_1_closed( double (*f)(double), double a, double b, double error=0.000001);
		Answer calculate_by_newton_cotes_deg_2_closed( double (*f)(double), double a, double b, double error=0.000001);
		Answer calculate_by_newton_cotes_deg_3_closed( double (*f)(double), double a, double b, double error=0.000001);
		Answer calculate_by_newton_cotes_deg_4_closed( double (*f)(double), double a, double b, double error=0.000001);

};