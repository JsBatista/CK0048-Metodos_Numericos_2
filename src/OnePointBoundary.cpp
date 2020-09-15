#include "OnePointBoundary.h"
#include <iostream>
#include <math.h>

// Construtor padrão
OnePointBoundary::OnePointBoundary()
{

}


void OnePointBoundary::eulerExplicitProblem1(int iterations, double v0, double y0, double k, double m, double deltaT, double t0)
{
    std::cout << "Iniciando Método de Euler Explícito com o Problema PVI - 2" << std::endl;

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


void OnePointBoundary::eulerImplicitProblem1(int iterations, double v0, double y0, double k, double m, double deltaT, double t0)
{
    std::cout << "Iniciando Método de Euler Implícito com o Problema PVI - 2" << std::endl;

    double g = 10;

    double v1, y1;
    double maxY = y1;
    double maxT = t0;
    double maxI = 0;

    bool onOcean = false;
        
    for(int i = 0; i < iterations; i++)
    {

        v1 = (m/(m+k*deltaT))*(v0 - g*deltaT);
        y1 = y0 + (m*deltaT/(m+k*deltaT))*(v0 - g*deltaT);
        
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


void OnePointBoundary::rungeKuttaProblem(int iterations, double v0, double y0, double k, double m, double deltaT, double t0)
{
std::cout << "Iniciando Método de Euler Implícito com o Problema PVI - 2" << std::endl;

    double g = 10;
    double c1 = 1.0/6.0;
    double c2 = 4.0/6.0;
    double c3 = c1;
    double v1, y1;

    double maxY = y1;
    double maxT = t0;
    double maxI = 0;

    bool onOcean = false;
        
    for(int i = 0; i < iterations; i++)
    {

        // Calculando estimativas grosseiras (barras)

        // Si+1/2  => Vi+1/2 e Yi+1/2
        double vip12 = v0 + (deltaT/2.0)*(-g-(k/m)*v0);
        double yip12 = y0 + (deltaT/2.0)*v0;

        // Si+1   =>  Vi+1 e Yi+1
        double vip1 = v0 + deltaT*( -(-g-(k/m)*v0) + 2*(-g-(k/m)*vip12));
        double yip1 = y0 + deltaT*( -v0 + 2*vip12 );

        // Calculando estado do próximo passo i+1
        v1 = v0 + deltaT*( c1*(-g-(k/m)*v0) + c2*(-g-(k/m)*vip12) + c3*(-g-(k/m)*vip1) );
        y1 = y0 + deltaT*( c1*v0 + c2*vip12 + c3*vip1 );

        // Verificação se o objeto chegou ao nível no mar, mostrando na tela quando isso ocorreu e com qual velocidade
        // Como raramente o objeto chega em exatamente 0, são mostrados os 2 passos, imediatamente antes e após a chegada do objeto no nível do mar
        if( y1 < 0)
        {

            std::cout << "Passos relevantes quanto à queda no mar: " << std::endl;
            std::cout << "T = " << t0 + i*deltaT+ deltaT << std::endl;
            std::cout << "V" << i+1 << " : " << v0 << std::endl;
            std::cout << "Y" << i+1 << " : " << y0 << std::endl << std::endl;
            
            i += 1;

            std::cout << "T = " << t0 + i*deltaT+ deltaT << std::endl;
            std::cout << "V" << i+1 << " : " << v1 << std::endl;
            std::cout << "Y" << i+1 << " : " << y1 << std::endl << std::endl;

            onOcean = true;
            i = iterations; 
        }
        // Atualizando valores para o cálculo do próximo passo
        v0 = v1;
        y0 = y1;

        // Registro da altura máxima do objeto
        if(maxY < y1)
        {
            maxY = y1;
            maxT = t0 + i*deltaT + deltaT;
            maxI = i+1;
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


/* 
std::cout << "Iniciando Método de Euler Implícito com o Problema PVI - 2" << std::endl;

    double g = 10;
    double c1 = 1.0/6.0;
    double c2 = 4.0/6.0;
    double c3 = c1;
    double v1, y1;

    double maxY = y1;
    double maxT = t0;
    double maxI = 0;

    bool onOcean = false;
        
    for(int i = 0; i < iterations; i++)
    {

        // Calculando estimativas grosseiras (barras)

        // Si+1/2  => Vi+1/2 e Yi+1/2
        double vip12 = v0 + (deltaT/2.0)*(-g-(k/m)*v0);
        double yip12 = y0 + (deltaT/2.0)*v0;

        // Si+1   =>  Vi+1 e Yi+1
        double vip1 = v0 + deltaT*( -(-g-(k/m)*v0) + 2*(-g-(k/m)*vip12));
        double yip1 = y0 + deltaT*( -v0 + 2*vip12 );

        // Calculando estado do próximo passo i+1
        v1 = v0 + deltaT*( c1*(-g-(k/m)*v0) + c2*(-g-(k/m)*vip12) + c3*(-g-(k/m)*vip1) );
        y1 = y0 + deltaT*( c1*v0 + c2*vip12 + c3*vip1 );

        // Verificação se o objeto chegou ao nível no mar, mostrando na tela quando isso ocorreu e com qual velocidade
        // Como raramente o objeto chega em exatamente 0, são mostrados os 2 passos, imediatamente antes e após a chegada do objeto no nível do mar
        if( y1 < 0)
        {

            std::cout << "Passos relevantes quanto à queda no mar: " << std::endl;
            std::cout << "T = " << t0 + i*deltaT << std::endl;
            std::cout << "V" << i+1 << " : " << v0 << std::endl;
            std::cout << "Y" << i+1 << " : " << y0 << std::endl << std::endl;
            
            v0 = v1;
            y0 = y1;
            i += 1;

            std::cout << "T = " << t0 + i*deltaT << std::endl;
            std::cout << "V" << i+1 << " : " << v1 << std::endl;
            std::cout << "Y" << i+1 << " : " << y1 << std::endl << std::endl;

            onOcean = true;
            i = iterations; 
        }
        // Atualizando valores para o cálculo do próximo passo
        v0 = v1;
        y0 = y1;

        // Registro da altura máxima do objeto
        if(maxY < y1)
        {
            maxY = y1;
            maxT = t0 + i*deltaT + deltaT;
            maxI = i+1;
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

    */