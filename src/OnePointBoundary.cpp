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
    double maxY = y1;
    double maxT = t0;
    double maxI = 0;

    bool onOcean = false;
        
    for(int i = 0; i < iterations; i++)
    {

        v1 = v0 + deltaT*(-g-(k*v0/m));
        y1 = y0 + deltaT*v0;
        
        v0 = v1;
        y0 = y1;

        // Registro da altura máxima do objeto
        if(maxY < y1)
        {
            maxY = y1;
            maxT = t0 + i*deltaT + deltaT;
            maxI = i+1;
        }

        // Verificação se o objeto chegou ao nível no mar, mostrando na tela quando isso ocorreu e com qual velocidade
        // Como raramente o objeto chega em exatamente 0, são mostrados os 2 passos, imediatamente antes e após a chegada do objeto no nível do mar
        if( y0 + deltaT*v0 < 0)
        {

            std::cout << "Passos relevantes quanto à queda no mar: " << std::endl;
            std::cout << "T = " << t0 + i*deltaT + deltaT << std::endl;
            std::cout << "V" << i+1 << " : " << v1 << std::endl;
            std::cout << "Y" << i+1 << " : " << y1 << std::endl << std::endl;
            
            v1 = v0 + deltaT*(-g-(k*v0/m));
            y1 = y0 + deltaT*v0;
            
            v0 = v1;
            y0 = y1;
            i += 1;

            std::cout << "T = " << t0 + i*deltaT + deltaT << std::endl;
            std::cout << "V" << i+1 << " : " << v1 << std::endl;
            std::cout << "Y" << i+1 << " : " << y1 << std::endl << std::endl;

            onOcean = true;
            i = iterations; 
        }
    }

    // Mostrando a altura máxima da trajetória e os dados referentes a esse passo
    std::cout << "Passo da altura máxima na trajetória: " << std::endl;
    std::cout << "T = " << maxT << std::endl;
    std::cout << "Y" << maxI << " : " << maxY << std::endl << std::endl;

    // Caso o objeto nunca chegue a cair no nivel do mar
    if(!onOcean)
    {
        std::cout << "Com esse número de passo não foi possível saber quando o objeto cairá no mar. " << std::endl;
        std::cout << "Dados do último passo: " << std::endl;
        std::cout << "T = " << t0 + iterations*deltaT << std::endl;
        std::cout << "V" << iterations << " : " << v1 << std::endl;
        std::cout << "Y" << iterations << " : " << y1 << std::endl << std::endl;
    }
    
    return;
}
