#include "Integrate.h"
#include <iostream>
#include <iomanip>
#include <math.h>

// Construtor padrão
Integrate::Integrate(){

}

/* Todas as funções abaixo diferenciam-se apenas na forma de cáculo da integral, mas toda seguem o roteiro::

	Definimos o número de iterações e de divisões da área

	Calculamos o valor da primeira interação

	Definimos um valor default para a segunda iteração pois este ainda não foi calculado

	Entramos em um laço que vai sempre:
		Dobrar o número de divisões e incrementar a iteração
		Calcular e somar as integrais para cada divisão da área
		Repetir se o resultado dessa iteração - resultado da iteração anterior for maior que o erro tolerado

	Retornamos um objeto Answer contendo as informações desejadas, o tempo não é mandado, logo, colocamos como 0 (zero)
*/

// Calcula a integral por Newton Cotes com o polinômio de interpolação de grau 1 com a abordagem fechada
Answer Integrate::calculate_by_newton_cotes_deg_1_closed( double (*f)(double), double a, double b, double error, bool debug)
{
	int iterations = 1;
	int n = 1;

	double r0 = ((b-a)/2)*(f(a)+f(b));
	if(debug)
	{
		std::cout << std::endl <<"[Início de Integração por Newton Cotes, grau 1, fechada]" << std::endl<< std::endl;
		std::cout << "Iteração 1: "<< std::fixed << std::setprecision(6) << r0 << std::endl<< std::endl;
	}


	// Valor default de 'não inicializado' para evitar um warning chato poluindo o terminal
	double r1 = -123456789;

	do
	{
		n *= 2;
		iterations += 1;
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
		
		if(debug)
		{
	
			std::cout << "Iteração " << iterations << ": " << r1 << std::endl;
			std::cout << "Diferença : "<< std::scientific << std::abs(r0-r1) << std::endl<< std::endl << std::fixed;
		}			


	} while (std::abs(r0-r1) > error);

	if(debug)
	{
		std::cout << std::endl <<"[Fim de Integração por Newton Cotes, grau 1, fechada]" << std::endl;
	}
	return Answer(r1, iterations, 0);
}


// Calcula a integral por Newton Cotes com o polinômio de interpolação de grau 2 com a abordagem fechada
Answer Integrate::calculate_by_newton_cotes_deg_2_closed( double (*f)(double), double a, double b, double error, bool debug)
{
	int iterations = 1;
	int n = 1;

	double h = ((b-a)/2);
	double r0 = (h/3)*( f(a) + 4*f(a + h) + f(b) );
	if(debug)
	{
		std::cout << std::endl <<"[Início de Integração por Newton Cotes, grau 2, fechada]" << std::endl<< std::endl;
		std::cout << "Iteração 1: "<< std::fixed << std::setprecision(6) << r0 << std::endl<< std::endl;
	}

	// Valor default de 'não inicializado' para evitar um warning chato poluindo o terminal
	double r1 = -123456789;

	do
	{
		n *= 2;
		iterations += 1;
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

		if(debug)
		{
			std::cout << "Iteração " << iterations << ": " << r1 << std::endl;
			std::cout << "Diferença : "<< std::scientific << std::abs(r0-r1) << std::endl<< std::endl << std::fixed;
		}	

	} while (std::abs(r0-r1) > error);
	if(debug)
	{
		std::cout << std::endl <<"[Fim de Integração por Newton Cotes, grau 2, fechada]" << std::endl;
	}
	return Answer(r1, iterations, 0);
}


// Calcula a integral por Newton Cotes com o polinômio de interpolação de grau 3 com a abordagem fechada
Answer Integrate::calculate_by_newton_cotes_deg_3_closed( double (*f)(double), double a, double b, double error, bool debug)
{
	int iterations = 1;
	int n = 1;

	double h = ((b-a)/3);
	double r0 = ((3*h)/8)*( f(a) + 3*f(a+h) + 3*f(a+2*h) + f(b) );
	if(debug)
	{
		std::cout << std::endl <<"[Início de Integração por Newton Cotes, grau 3, fechada]" << std::endl<< std::endl;
		std::cout << "Iteração 1: "<< std::fixed << std::setprecision(6) << r0 << std::endl<< std::endl;
	}

	// Valor default de 'não inicializado' para evitar um warning chato poluindo o terminal
	double r1 = -123456789;

	do
	{
		n *= 2;
		iterations += 1;
		double variation = (b-a)/n;


		double sum = 0;
		for( double x0 = a; x0 < b; x0 += variation )
		{
			double h = (variation/3);
			sum += ((3*h)/8)*( f(x0) + 3*f(x0+h) + 3*f(x0+2*h) + f(x0+variation) );
		};
		if(n!=2)
		{
			r0 = r1;
		}
		r1 = sum;

		if(debug)
		{
			std::cout << "Iteração " << iterations << ": " << r1 << std::endl;
			std::cout << "Diferença : "<< std::scientific << std::abs(r0-r1) << std::endl<< std::endl << std::fixed;
		}	

	} while (std::abs(r0-r1) > error);
	if(debug)
	{
		std::cout << std::endl <<"[Fim de Integração por Newton Cotes, grau 3, fechada]" << std::endl;
	}
	return Answer(r1, iterations, 0);
}


// Calcula a integral por Newton Cotes com o polinômio de interpolação de grau 4 com a abordagem fechada
Answer Integrate::calculate_by_newton_cotes_deg_4_closed( double (*f)(double), double a, double b, double error, bool debug)
{
	int iterations = 1;
	int n = 1;


	double h = ((b-a)/4);
	double r0 = ((2*h)/45)*( 7*f(a) + 32*f(a+h) + 12*f(a+2*h) + 32*f(a+3*h) +7*f(b));
	if(debug)
	{
		std::cout << std::endl <<"[Início de Integração por Newton Cotes, grau 4, fechada]" << std::endl<< std::endl;
		std::cout << "Iteração 1: "<< std::fixed << std::setprecision(6) << r0 << std::endl<< std::endl;
	}
	

	// Valor default de 'não inicializado' para evitar um warning chato poluindo o terminal
	double r1 = -123456789;

	do
	{
		n *= 2;
		iterations += 1;
		double variation = (b-a)/n;


		double sum = 0;
		for( double x0 = a; x0 < b; x0 += variation )
		{
			double h = (variation/4);
			sum += ((2*h)/45)*( 7*f(x0) + 32*f(x0+h) + 12*f(x0+2*h) + 32*f(x0+3*h) +7*f(x0+variation));
			
		};
		if(n!=2)
		{
			r0 = r1;
		}
		r1 = sum;

		if(debug)
		{
			std::cout << "Iteração " << iterations << ": " << r1 << std::endl;
			std::cout << "Diferença : "<< std::scientific << std::abs(r0-r1) << std::endl<< std::endl << std::fixed;
		}	

	} while (std::abs(r0-r1) > error);
	if(debug)
	{
		std::cout << std::endl <<"[Fim de Integração por Newton Cotes, grau 4, fechada]" << std::endl;
	}
	return Answer(r1, iterations, 0);
}


// Calcula a integral por Newton Cotes com o polinômio de interpolação de grau 1 com a abordagem aberta
Answer Integrate::calculate_by_newton_cotes_deg_1_open( double (*f)(double), double a, double b, double error, bool debug)
{
	int iterations = 1;
	int n = 1;

	double h = (b-a)/3;
	double r0 = ((b-a)/2)*( f(a+h)+f(a+2*h) );
	if(debug)
	{
		std::cout << std::endl <<"[Início de Integração por Newton Cotes, grau 1, aberta]" << std::endl<< std::endl;
		std::cout << "Iteração 1: "<< std::fixed << std::setprecision(6) << r0 << std::endl<< std::endl;
	}
	

	// Valor default de 'não inicializado' para evitar um warning chato poluindo o terminal
	double r1 = -123456789;

	do
	{
		n *= 2;
		iterations += 1;
		double variation = (b-a)/n;


		double sum = 0;
		for( double x0 = a; x0 < b; x0 += variation )
		{	
			double h = (variation)/3;
			sum += ((variation)/2)*( f(x0+h)+f(x0+2*h) );
		};
		if(n!=2)
		{
			r0 = r1;
		}
		r1 = sum;

		if(debug)
		{
			std::cout << "Iteração " << iterations << ": " << r1 << std::endl;
			std::cout << "Diferença : "<< std::scientific << std::abs(r0-r1) << std::endl<< std::endl << std::fixed;
		}	

	} while (std::abs(r0-r1) > error);
	if(debug)
	{
		std::cout << std::endl <<"[Início de Integração por Newton Cotes, grau 1, aberta]" << std::endl;
	}
	return Answer(r1, iterations, 0);
}

// Calcula a integral por Newton Cotes com o polinômio de interpolação de grau 2 com a abordagem aberta
Answer Integrate::calculate_by_newton_cotes_deg_2_open( double (*f)(double), double a, double b, double error, bool debug)
{
	int iterations = 1;
	int n = 1;

	double h = (b-a)/4;
	double r0 = ((4*h)/3)*( 2*f(a+h) -f(a+2*h) + 2*f(a + 3*h));

	if(debug)
	{
		std::cout << std::endl <<"[Início de Integração por Newton Cotes, grau 2, aberta]" << std::endl<< std::endl;
		std::cout << "Iteração 1: "<< std::fixed << std::setprecision(6) << r0 << std::endl<< std::endl;
	}
	

	// Valor default de 'não inicializado' para evitar um warning chato poluindo o terminal
	double r1 = -123456789;

	do
	{
		n *= 2;
		iterations += 1;
		double variation = (b-a)/n;


		double sum = 0;
		for( double x0 = a; x0 < b; x0 += variation )
		{	
			double h = (variation)/4;
			sum += ((4*h)/3)*( 2*f(x0+h) -f(x0+2*h) + 2*f(x0 + 3*h));

		};
		if(n!=2)
		{
			r0 = r1;
		}
		r1 = sum;

		if(debug)
		{
			std::cout << "Iteração " << iterations << ": " << r1 << std::endl;
			std::cout << "Diferença : "<< std::scientific << std::abs(r0-r1) << std::endl<< std::endl << std::fixed;
		}	

	} while (std::abs(r0-r1) > error);
	if(debug)
	{
		std::cout << std::endl <<"[Fim de Integração por Newton Cotes, grau 2, aberta]" << std::endl;
	}
	return Answer(r1, iterations, 0);
}


// Calcula a integral por Newton Cotes com o polinômio de interpolação de grau 3 com a abordagem aberta
Answer Integrate::calculate_by_newton_cotes_deg_3_open( double (*f)(double), double a, double b, double error, bool debug)
{
	int iterations = 1;
	int n = 1;

	double h = (b-a)/5;
	double r0 = ((5*h)/24) * ( 11*f(a+h) + f(a+2*h) + f(a + 3*h) + 11*f(a + 4*h));

	if(debug)
	{
		std::cout << std::endl <<"[Início de Integração por Newton Cotes, grau 3, aberta]" << std::endl<< std::endl;
		std::cout << "Iteração 1: "<< std::fixed << std::setprecision(6) << r0 << std::endl<< std::endl;
	}

	// Valor default de 'não inicializado' para evitar um warning chato poluindo o terminal
	double r1 = -123456789;

	do
	{
		n *= 2;
		iterations += 1;
		double variation = (b-a)/n;


		double sum = 0;
		for( double x0 = a; x0 < b; x0 += variation )
		{	
			double h = (variation)/5;
			sum += ((5*h)/24) * ( 11*f(x0+h) + f(x0+2*h) + f(x0 + 3*h) + 11*f(x0 + 4*h));

		};
		if(n!=2)
		{
			r0 = r1;
		}
		r1 = sum;

		if(debug)
		{
			std::cout << "Iteração " << iterations << ": " << r1 << std::endl;
			std::cout << "Diferença : "<< std::scientific << std::abs(r0-r1) << std::endl<< std::endl << std::fixed;
		}	

	} while (std::abs(r0-r1) > error);
	
	if(debug)
	{
		std::cout << std::endl <<"[Fim de Integração por Newton Cotes, grau 3, aberta]" << std::endl;
	}
	return Answer(r1, iterations, 0);
}


// Calcula a integral por Newton Cotes com o polinômio de interpolação de grau 4 com a abordagem aberta
Answer Integrate::calculate_by_newton_cotes_deg_4_open( double (*f)(double), double a, double b, double error, bool debug)
{
	int iterations = 1;
	int n = 1;

	double h = (b-a)/6;
	double r0 = ((6*h)/20) * ( 11*f(a+h) - 14*f(a+2*h) + 26*f(a + 3*h) -14*f(a + 4*h) + 11*f(a+5*h));

	if(debug)
	{
		std::cout << std::endl <<"[Início de Integração por Newton Cotes, grau 4, aberta]" << std::endl<< std::endl;
		std::cout << "Iteração 1: "<< std::fixed << std::setprecision(6) << r0 << std::endl<< std::endl;
	}

	// Valor default de 'não inicializado' para evitar um warning chato poluindo o terminal
	double r1 = -123456789;

	do
	{
		n *= 2;
		iterations += 1;
		double variation = (b-a)/n;


		double sum = 0;
		for( double x0 = a; x0 < b; x0 += variation )
		{	
			double h = (variation)/6;
			sum += ((6*h)/20) * ( 11*f(x0+h) - 14*f(x0+2*h) + 26*f(x0 + 3*h) -14*f(x0 + 4*h) + 11*f(x0+5*h));

		};
		if(n!=2)
		{
			r0 = r1;
		}
		r1 = sum;

		if(debug)
		{
			std::cout << "Iteração " << iterations << ": " << r1 << std::endl;
			std::cout << "Diferença : "<< std::scientific << std::abs(r0-r1) << std::endl<< std::endl << std::fixed;
		}	

	} while (std::abs(r0-r1) > error);

	if(debug)
	{
		std::cout << std::endl <<"[Fim de Integração por Newton Cotes, grau 4, aberta]" << std::endl;
	}
	return Answer(r1, iterations, 0);
}