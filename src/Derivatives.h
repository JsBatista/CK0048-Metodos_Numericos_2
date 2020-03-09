#pragma once

#include "Answer.h"

class Derivatives
{
	public:
		Derivatives();
		Answer calculate_forward( double (*f)(double), double x, double delta_x);
};