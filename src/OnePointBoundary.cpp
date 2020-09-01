#include "OnePointBoundary.h"
#include <iostream>
#include <math.h>

// Construtor padrão
OnePointBoundary::OnePointBoundary()
{

}


void OnePointBoundary::eulerExplicitProblem1(int iterations, double v0, double y0, double k, double m, double deltaT, double t0)
{
    std::cout << "Starting Euler Explicit Method with Problem 1" << std::endl;

    double g = 10;

    double v1, y1;
    double max = -999;
    double maxT, yT, maxI;
    std::cout << "T = " << t0 << std::endl;
    std::cout << "V0: " << v0 << std::endl;
    std::cout << "Y0: " << y0 << std::endl << std::endl;
        
    for(int i = 0; i < iterations; i++)
    {
        v1 = v0 + deltaT*(-g-(k*v0/m));
        y1 = y0 + deltaT*v0;
        std::cout << "T = " << t0 + i*deltaT + deltaT << std::endl;
        std::cout << "V" << i+1 << " : " << v1 << std::endl;
        std::cout << "Y" << i+1 << " : " << y1 << std::endl << std::endl;
        v0 = v1;
        y0 = y1;
        /*if(max < y1)
        {
            maxT = i*deltaT + deltaT;
            yT = y1;
            maxI = i;
        }*/
        if(y1 <= -0.1)
        {
            i = iterations;
        }
    }

    //std::cout << "T = " << maxT << std::endl;
    //std::cout << "I  = " << maxI << std::endl;
    //std::cout << "Yt = " << yT << std::endl;

    return;
}
