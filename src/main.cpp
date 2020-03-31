#include <iostream>
#include <vector>
#include "Answer.h"
#include "Derivatives.h"
#include "Integrate.h"
#include <math.h>
#include <string>

double f( double x )
{
    return std::pow((std::sin(2*x) +(4*x*x) + 3*x), 2);
}

int main() 
{


    //const double pi = 3.1415926535897;

    Integrate i;

    Answer a = i.calculate_by_newton_cotes_deg_1_closed( &f, 0, 1);
    Answer b = i.calculate_by_newton_cotes_deg_2_closed( &f, 0, 1);
    Answer c = i.calculate_by_newton_cotes_deg_3_closed( &f, 0, 1);
    Answer d = i.calculate_by_newton_cotes_deg_4_closed( &f, 0, 1);

    std::cout << std::endl;

    std::cout << "Integral grau 1: " << a.getResult() << std::endl;
    std::cout << "Iterações: " << a.getIterations() << std::endl << std::endl;


    std::cout << "Integral grau 2: " << b.getResult() << std::endl;
    std::cout << "Iterações: " << b.getIterations() << std::endl<< std::endl;


    std::cout << "Integral grau 3: " << c.getResult() << std::endl;
    std::cout << "Iterações: " << c.getIterations() << std::endl<< std::endl;


    std::cout << "Integral grau 4: " << d.getResult() << std::endl;
    std::cout << "Iterações: " << d.getIterations() << std::endl<< std::endl;

    return 0;

}

