#pragma once

#include <functional>
#include "Answer.h"

class Integrate
{

	public:
		Integrate();
		Answer calculate_by_newton_cotes_deg_1_closed( double (*f)(double), double a, double b, double error=0.000001, bool debug=false);
		Answer calculate_by_newton_cotes_deg_2_closed( double (*f)(double), double a, double b, double error=0.000001, bool debug=false);
		Answer calculate_by_newton_cotes_deg_3_closed( double (*f)(double), double a, double b, double error=0.000001, bool debug=false);
		Answer calculate_by_newton_cotes_deg_4_closed( double (*f)(double), double a, double b, double error=0.000001, bool debug=false);

		Answer calculate_by_newton_cotes_deg_1_open( double (*f)(double), double a, double b, double error=0.000001, bool debug=false);
		Answer calculate_by_newton_cotes_deg_2_open( double (*f)(double), double a, double b, double error=0.000001, bool debug=false);
		Answer calculate_by_newton_cotes_deg_3_open( double (*f)(double), double a, double b, double error=0.000001, bool debug=false);
		Answer calculate_by_newton_cotes_deg_4_open( double (*f)(double), double a, double b, double error=0.000001, bool debug=false);

		Answer calculate_by_gauss_legendre_2(double (*f)(double), double a, double b, double error=0.000001, bool debug=false);
		Answer calculate_by_gauss_legendre_3(double (*f)(double), double a, double b, double error=0.000001, bool debug=false);
		Answer calculate_by_gauss_legendre_4(double (*f)(double), double a, double b, double error=0.000001, bool debug=false);

		Answer calculate_by_gauss_hermite(const std::function<double( double )> &f, int n, bool debug = false);
		Answer calculate_by_gauss_laguerre(double (*f)(double), int n, bool debug = false);
		Answer calculate_by_gauss_chebyshev(double (*f)(double), int n, bool debug = false);

		Answer calculate_by_singularity_gh(double (*f)(double), double a, double b, int n, bool simple, double error=0.000001, bool debug=false);
		Answer calculate_by_singularity_gh_double(double (*f)(double), double a, double b, double error=0.000001, bool debug=false);

};