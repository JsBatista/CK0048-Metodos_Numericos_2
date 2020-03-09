#include "Derivatives.h"

Derivatives::Derivatives(){

}

Answer Derivatives::calculate_forward( double (*f)(double), double x, double delta_x)
{
	return Answer( ((f(x+delta_x) - f(x) ) / delta_x), 1, -1.0 );
}