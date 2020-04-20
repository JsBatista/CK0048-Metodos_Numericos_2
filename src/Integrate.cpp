#include "Integrate.h"
#include <iostream>
#include <iomanip>
#include <math.h>
#include <functional>

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


// Calcula a Integral por Gauss Legendre usando 2 pontos
Answer Integrate::calculate_by_gauss_legendre_2( double (*f)(double), double a, double b, double error, bool debug)
{

	int iterations = 1;
	int n = 1;

	// Calculamos os x(alpha)
	// 										a1 = - raiz(1/3)		
	double xa1 = ((a + b) / 2) + ((b-a)/2)*(-0.577350269);
	// 										a2 = raiz(1/3)	
	double xa2 = ((a + b) / 2) + ((b-a)/2)*(0.577350269);	

	// 							  w1 = 1     w2 = 2
	double r0 = ((b-a)/2)*( f(xa1)*1 + f(xa2)*1 );


	if(debug)
	{
		std::cout << std::endl <<"[Início de Integração por Newton Legendre, 2 pontos]" << std::endl<< std::endl;
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
			// 			   X0 + XF = X0 + Xo + Variacao
			// 			   XF - X0 = X0 + Variacao - X0 = Variacao
			double xa1 = ((x0 + x0 + variation) / 2) + ((variation)/2)*(-0.577350269);
			double xa2 = ((x0 + x0 + variation) / 2) + ((variation)/2)*(0.577350269);	

			sum += ((variation)/2)*( f(xa1) + f(xa2) );
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
		std::cout << std::endl <<"[Fim de Integração por Newton Legendre, 2 pontos]" << std::endl;
	}
	return Answer(r1, iterations, 0);
}


// Calcula a Integral por Gauss Legendre usando 3 pontos
Answer Integrate::calculate_by_gauss_legendre_3( double (*f)(double), double a, double b, double error, bool debug)
{

	int iterations = 1;
	int n = 1;

	// Calculamos os x(alpha)
	// 										a1 = - raiz(3/5)		
	double xa1 = ((a + b) / 2) + ((b-a)/2)*(-0.774596669);
	// 							a2 = 0
	double xa2 = ((a + b) / 2);
	// 										a3 = raiz(3/5)	
	double xa3 = ((a + b) / 2) + ((b-a)/2)*(0.774596669);	 

	//									w1				  w2				w3
	double r0 = ((b-a)/2)*( f(xa1)*(5.0/9.0) + f(xa2)*(8.0/9.0) + f(xa3)*(5.0/9.0) );


	if(debug)
	{
		std::cout << std::endl <<"[Início de Integração por Newton Legendre, 3 pontos]" << std::endl<< std::endl;
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
			// 			   X0 + XF = X0 + Xo + Variacao
			// 			   XF - X0 = X0 + Variacao - X0 = Variacao
			double xa1 = ((x0 + x0 + variation) / 2) + ((variation)/2)*(-0.774596669);
			double xa2 = ((x0 + x0 + variation) / 2);	
			double xa3 = ((x0 + x0 + variation) / 2) + ((variation)/2)*(0.774596669);	


			sum += ((variation)/2)*( f(xa1)*(5.0/9.0) + f(xa2)*(8.0/9.0) + f(xa3)*(5.0/9.0) );

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
		std::cout << std::endl <<"[Fim de Integração por Newton Legendre, 3 pontos]" << std::endl;
	}
	return Answer(r1, iterations, 0);
}


// Calcula a Integral por Gauss Legendre usando 4 pontos
Answer Integrate::calculate_by_gauss_legendre_4( double (*f)(double), double a, double b, double error, bool debug)
{

	int iterations = 1;
	int n = 1;

	// Calculamos os x(alpha)
	// 											a1 
	double xa1 = ((a + b) / 2) + ((b-a)/2)*(-0.861136311);
	// 											a2
	double xa2 = ((a + b) / 2) + ((b-a)/2)*(-0.339981043);
	// 											a3
	double xa3 = ((a + b) / 2) + ((b-a)/2)*(0.339981043);
	// 											a4	 
	double xa4 = ((a + b) / 2) + ((b-a)/2)*(0.861136311);	 


	double r0 = ((b-a)/2)*( f(xa1)*(0.3478548451) + f(xa2)*(0.6521451548) + f(xa3)*(0.6521451548) + f(xa4)*(0.3478548451) );


	if(debug)
	{
		std::cout << std::endl <<"[Início de Integração por Newton Legendre, 4 pontos]" << std::endl<< std::endl;
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
			// 			   X0 + XF = X0 + Xo + Variacao
			// 			   XF - X0 = X0 + Variacao - X0 = Variacao
			double xa1 = ((x0 + x0 + variation) / 2) + ((variation)/2)*(-0.861136311);
			double xa2 = ((x0 + x0 + variation) / 2) + ((variation)/2)*(-0.339981043);
			double xa3 = ((x0 + x0 + variation) / 2) + ((variation)/2)*(0.339981043);	 
			double xa4 = ((x0 + x0 + variation) / 2) + ((variation)/2)*(0.861136311);	 


			sum += ((variation)/2)*( f(xa1)*(0.3478548451) + f(xa2)*(0.6521451548) + f(xa3)*(0.6521451548) + f(xa4)*(0.3478548451) );

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
		std::cout << std::endl <<"[Fim de Integração por Newton Legendre, 4 pontos]" << std::endl;
	}
	return Answer(r1, iterations, 0);
}


/* Os 3 métodos abaixo calculam integrações usando o seguinte roteiro em uma única iteração:
	
	Defini-se as raízes X e os pesos W
	Dependendo do número de pontos especificado, realiza-se o cálculo com as raízes e pesos apropriados
	Retorna a resposta com 1 iteração

	Caso o n passado não esteja definido, a função retorna uma resposta de Erro com resultado -1 e uma mensagem apropriada.

*/

// Calcula a Integral Especial por Gauss Hermite usando 2, 3 ou 4 pontos
Answer Integrate::calculate_by_gauss_hermite(const std::function<double( double )> &f, int n, bool debug)
{
	switch (n)
	{
		// Declarando variáveis aqui para evitar erros de redeclaração
		double x1,x2,x3,x4;
		double w1,w2,w3,w4;
	    double result;

	    case 2:
	     	// 1 / sqrt(2) e -1 / sqrt(2)
	     	x1 = 0.707106781;
	     	x2 = -0.707106781;

	     	// sqrt(pi) e sqrt(pi)
	     	w1 = 0.886226925;
	     	w2 = w1;

	     	result = f(x1)*w1 + f(x2)*w2;

	     	return Answer(result, 1, 0);
			
			break;

	     case 3:
	     	// sqrt(3/2), 0 e -sqrt(3/2)
	     	x1 = 1.224744871;
	     	x2 = 0;
	     	x3 = -1.224744871;

	     	// sqrt(pi)/6, 2*sqrt(pi)/3 e sqrt(pi)/6
	     	w1 = 0.295408975;
	     	w2 = 1.181635901;
	     	w3 = w1;

	     	result = f(x1)*w1 + f(x2)*w2 + f(x3)*w3;

	     	return Answer(result, 1, 0);
			
			break;

		case 4:
	     	// sqrt(3/2), 0 e -sqrt(3/2)
	     	x1 = 1.65068012;
	     	x2 = 0.52464762;
	     	x3 = -0.52464762;
	     	x4 = -1.65068012;

	     	// sqrt(pi)/6, 2*sqrt(pi)/3 e sqrt(pi)/6
	     	w1 = 0.045875855*sqrt(3.141592654);
	     	w2 = 0.454124148*sqrt(3.141592654);
	     	w3 = w2;
	     	w4 = w1;

	     	result = f(x1)*w1 + f(x2)*w2 + f(x3)*w3 + f(x4)*w4;

	     	return Answer(result, 1, 0);
			
			break;


	    return Answer("Método não implementado para essa quantia de pontos.");

	}
}

// Calcula a Integral Especial por Gauss Laguerre usando 2, 3 ou 4 pontos
Answer Integrate::calculate_by_gauss_laguerre(double (*f)(double), int n, bool debug)
{
	switch (n)
	{
		// Declarando variáveis aqui para evitar erros de redeclaração
		double x1,x2,x3,x4;
		double w1,w2,w3,w4;
	    double result;

	    case 2:
	     	// 2 - sqrt(2) e 2 + sqrt(2)
	     	x1 = 0.585786437;
	     	x2 = 3.414213562;

	     	// (1/4)*(2 + sqrt(2)) e (1/4)*(2 - sqrt(2)) 
	     	w1 = 0.85355339;
	     	w2 = 0.146446609;

	     	result = f(x1)*w1 + f(x2)*w2;

	     	return Answer(result, 1, 0);
			
			break;

	     case 3:

			// Valores resultantes já tabelados	     	
	     	x1 = 0.4157745568;
	     	x2 = 2.2942803603;
	     	x3 = 6.2899450829;

	     	// Valores resultantes já tabelados
	     	w1 = 0.7110930099;
	     	w2 = 0.2785177336;
	     	w3 = 0.0103892565;

	     	result = f(x1)*w1 + f(x2)*w2 + f(x3)*w3;

	     	return Answer(result, 1, 0);
			
			break;

		case 4:
	     	// Valores resultantes já tabelados
	     	x1 = 0.322547689619370;
	     	x2 = 1.745761101158365;
	     	x3 = 4.536620296921143;
	     	x4 = 9.395070912301122;

	     	// Valores resultantes já tabelados
	     	w1 = 0.6031541043420089;
	     	w2 = 0.3574186924377639;
	     	w3 = 0.038887908515004704;
	     	w4 = 0.0005392947055613193;

	     	result = f(x1)*w1 + f(x2)*w2 + f(x3)*w3 + f(x4)*w4;

	     	return Answer(result, 1, 0);
			
			break;


	    return Answer("Método não implementado para essa quantia de pontos.");

	}
}

// Calcula a Integral Especial por Gauss Chebyshev usando 2, 3 ou 4 pontos
Answer Integrate::calculate_by_gauss_chebyshev(double (*f)(double), int n, bool debug)
{
	// Declarando variáveis aqui para evitar erros de redeclaração
	double x1,x2,x3,x4;

	// OBS: w1 = w2 = w3 = w4 = pi / n sempre
	double w = 3.141592654 / n;
    
    double result;

	switch (n)
	{

	    case 2:
	     	// -1/sqrt(2) e 1/sqrt(2) 
	     	x1 = -0.707106781;
	     	x2 = 0.707106781;

	     	result = f(x1)*w + f(x2)*w;

	     	return Answer(result, 1, 0);
			
			break;

	     case 3:

			// -sqrt(3)/2 , 0 e sqrt(3)/2 
	     	x1 = -0.866025403;
	     	x2 = 0;
	     	x3 = 0.866025403;


	     	result = f(x1)*w + f(x2)*w + f(x3)*w;

	     	return Answer(result, 1, 0);
			
			break;

		case 4:
	     	// Valores resultantes já tabelados
	     	x1 = -0.923879532;
	     	x2 = -0.382683432;
	     	x3 = 0.382683432;
	     	x4 = 0.923879532;

	     	result = f(x1)*w + f(x2)*w + f(x3)*w + f(x4)*w;

	     	return Answer(result, 1, 0);
			
			break;


	    return Answer("Método não implementado para essa quantia de pontos.");

	}
}




// Calculo de intervalos singulares usando a estratégia de Gauss-Hermite até 4 pontos
// Parâmetros:
/*
	f: Função desejada para integração
	a: Início do intervalo de integração
	b: Fim do intervalo de integração
	n: Número de pontos a serem usados no método de Gauss-Hermite
	simple: Booleano que, se for Verdadeiro, indica que usaremos a estratégia de Exponencial Simples
			Caso contrário, usaremos a estratégia de Exponencial Dupla
*/
Answer Integrate::calculate_by_singularity_gh(double (*f)(double), double a, double b, int n, bool simple ,double error,bool debug)
{
	const double e = std::exp(1.0);
	const double PI  =3.141592653589793238463;


 	auto fun = [&](double s) 
	{ 
		if(simple){
		    //               e^(x^2)   * (f((a+b)/2 + ((b-a)/2)tanh(s)) ) * ( (b-a)/(2*cosh(s)^2) )
			return std::pow(e, (s*s) ) *  f( ((a+b)/2) + ((b-a)/2)*std::tanh(s) ) * ( (b-a)/(2*( std::pow(std::cosh(s), 2) ) ) );
		};

		return std::pow(e, (s*s) ) * f( (a+b)/2 + ((b-a)/2)*std::tanh( (PI/2)*std::sinh(s) ) ) * ( ((b-a)/2)*( (PI*std::cosh(s)) / (2*std::pow(std::cosh( (PI/2)*std::sinh(s) ), 2)  ) ));
	};

	return Integrate::calculate_by_gauss_hermite(fun, n);
}


