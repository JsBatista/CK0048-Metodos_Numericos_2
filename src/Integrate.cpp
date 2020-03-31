#include "Integrate.h"
#include <iostream>
#include <math.h>

Integrate::Integrate(){

}

Answer Integrate::calculate_by_newton_cotes_deg_1( double (*f)(double), double a, double b, double error)
{
	int iterations = 1;
	int n = 1;

	double r0 = ((a-b)/2)*(f(a)+f(b));
	std::cout << "Iteração 1: " << r0 << std::endl;

	double r1;

	do
	{
		n *= 2;
		iterations += 1;
		double multiplicative = 0;
		double variation = (b-a)/n;


		double sum = 0;
		for( double x0 = a; x0 < b; x0 += variation )
		{
			sum += (variation/2)*(f(x0)+f(x0+variation));
		};
		if(n!=2)
		{
			r0 = r1;
		}
		r1 = sum;

		std::cout << "Iteração " << iterations << ": " << r1 << std::endl;
		//std::cout << "Diferença :" << std::abs(r0-r1) << std::endl << std::endl;

	} while (std::abs(r0-r1) > error);

	return Answer(r1, iterations, 0);
}

Answer Integrate::calculate_by_newton_cotes_deg_2( double (*f)(double), double a, double b, double error)
{
	int iterations = 1;
	int n = 1;

	double h = ((b-a)/2);
	double r0 = (h/3)*( f(a) + 4*f(a + h) + f(b) );
	std::cout << "Iteração 1: " << r0 << std::endl;

	double r1;

	do
	{
		n *= 2;
		iterations += 1;
		double multiplicative = 0;
		double variation = (b-a)/n;


		double sum = 0;
		for( double x0 = a; x0 < b; x0 += variation )
		{
			double h = (variation/2);
			sum += (h/3)*( f(x0) + 4*f(x0 + h) + f(x0+variation) );
		};
		if(n!=2)
		{
			r0 = r1;
		}
		r1 = sum;

		std::cout << "Iteração " << iterations << ": " << r1 << std::endl;
		//std::cout << "Diferença :" << std::abs(r0-r1) << std::endl << std::endl;

	} while (std::abs(r0-r1) > error);

	return Answer(r1, iterations, 0);
}
