#include "Derivatives.h"
#include <iostream>
#include <math.h>

Derivatives::Derivatives(){

}

Answer Derivatives::calculate_forward( double (*f)(double), double x, double delta_x)
{
	return Answer( ((f(x+delta_x) - f(x) ) / delta_x), 1, -1.0 );
}

Answer Derivatives::calculate_backwards( double (*f)(double), double x, double delta_x)
{
	return Answer( (( f(x) - f(x - delta_x) ) / delta_x), 1, -1.0 );
}

Answer Derivatives::calculate_central( double (*f)(double), double x, double delta_x)
{
	return Answer( (( f(x + delta_x) - f(x - delta_x) ) / (2*delta_x) ), 1, -1.0 );
}


Answer Derivatives::calculate_second_forward( double (*f)(double), double x, double delta_x)
{
	double result = (1/ std::pow(delta_x, 2) ) * ( f(x+2*delta_x) -2*f(x+delta_x) + f(x) );
	return Answer( result , 1, -1.0 );
}


Answer Derivatives::calculate_second_backwards( double (*f)(double), double x, double delta_x)
{
	double result = (1/ std::pow(delta_x, 2) ) * ( f(x-2*delta_x) -2*f(x-delta_x) + f(x) );
	return Answer( result , 1, -1.0 );
}

Answer Derivatives::calculate_second_central( double (*f)(double), double x, double delta_x)
{
	
	double result = (1/ (4*std::pow(delta_x, 2)) ) * ( f(x+2*delta_x) -2*f(x) + f(x -2*delta_x) );
	return Answer( result , 1, -1.0 );
}