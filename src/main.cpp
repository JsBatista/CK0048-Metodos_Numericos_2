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


    const double pi = 3.1415926535897;

    Integrate i;

    Answer a = i.calculate_by_newton_cotes_deg_2( &f, 0, 1);

    std::cout << "Integral grau 1: " << a.getResult() << std::endl;
    std::cout << "Iterações: " << a.getIterations() << std::endl;

    return 0;

}

