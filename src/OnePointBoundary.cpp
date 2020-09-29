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


void OnePointBoundary::predictorCorrector(int iterations, double v0, double y0, double k, double m, double deltaT, double t0, double error)
{

    double g = 10;
    double v1, y1;

    v1 = v0;
    y1 = v0;

    // Fi
    double Fvi, Fyi;
    // Fi-1
    double Fvi1, Fyi1;
    // Fi-2
    double Fvi2, Fyi2;
    // Fi-3
    double Fvi3 = (-g-(k/m)*v0);
    double Fyi3 = v0;

    double maxY = y0;
    double maxT = t0;
    double maxI = 0;


    // Calculando os passos S1 e S2 por Runge Kutta de Quarta Ordem:

    for(int i = 0; i < 3; i++)
    {

        // Fórmula T1
        double F1v = (-g-(k/m)*v1);
        double F1y = v1;

        // Fórmula T2
        double v2 = v1 + (deltaT/2.0)*F1v;
        double y2 = y1 + (deltaT/2.0)*F1y;

        // Fórmula T3
        double F2v = (-g-(k/m)*v2);
        double F2y = v2;

        // Fórmula T4
        double v3 = v1 + (deltaT/2.0)*F2v;
        double y3 = y1 + (deltaT/2.0)*F2y;

        // Fórmula T5
        double F3v = (-g-(k/m)*v3);
        double F3y = v3;

        // Fórmula T6
        double v4 = v1 + (deltaT)*F3v;
        double y4 = y1 + (deltaT)*F3y;

        // Fórmula T7
        double F4v = (-g-(k/m)*v4);
        double F4y = v4;

        // Cálculo de Si+1
        v1 = v0 + (deltaT/6.0)*(F1v + 2*F2v + 2*F3v + F4v);
        y1 = y0 + (deltaT/6.0)*(F1y + 2*F2y + 2*F3y + F4y);

        v0 = v1;
        y0 = y1;

        // Salvando resultados das 3 primeiras alterações nas variáveis apropriadas
        if(i == 0){
            Fvi2 = (-g-(k/m)*v0);
            Fyi2 = v0;
        }
        if(i == 1){
            Fvi1 = (-g-(k/m)*v0);
            Fyi1 = v0;
        }
        if(i == 2){
            Fvi = (-g-(k/m)*v0);
            Fyi = v0;
        }


        // Verificação se o objeto chegou ao nível no mar, mostrando na tela quando isso ocorreu e com qual velocidade
        // Como raramente o objeto chega em exatamente 0, são mostrados os passos próximos a chegada do nivel do mar
        // Usei como padrão de aproximação o inteiro 1 já que consegue mostrar com precisão os passos até a chegada do mar
        // Esse valor poderá ser ajustado para mostrar mais ou menos iterações
        if( std::abs(y1) < 1 )
        {

            std::cout << "Passos relevantes quanto à queda no mar: " << std::endl;
            std::cout << "T = " << t0 + i*deltaT+ deltaT << std::endl;
            std::cout << "V" << i+1 << " : " << v0 << std::endl;
            std::cout << "Y" << i+1 << " : " << y0 << std::endl << std::endl;
        }

        if(maxY < y1)
        {
            maxY = y1;
            maxT = t0 + i*deltaT + deltaT;
            maxI = i+1;
        }
    }

    for(int i = 3; i < iterations; i ++)
    {
        // Estimação do estado Si+1
        // Si+1 barra
        double Simais1BarraV = v0 + (deltaT/24.0)*(55*Fvi - 59*Fvi1 + 37*Fvi2 -9*Fvi3);
        double Simais1BarraY = y0 + (deltaT/24.0)*(55*Fyi - 59*Fyi1 + 37*Fyi2 -9*Fyi3);
        
        double Fimais1BarraV = (-g-(k/m)*Simais1BarraV);
        double Fimais1BarraY = Simais1BarraV;

        double Simais1V, Simais1Y;

        Simais1V = v0 + (deltaT/24.0)*(Fvi2 -5*Fvi1 +19*Fvi +9*Fimais1BarraV);
        Simais1Y = y0 + (deltaT/24.0)*(Fyi2 -5*Fyi1 +19*Fyi +9*Fimais1BarraY);

        double Simais1Vk = -976; // Valor default de primeira iteração
        double Simais1Yk = -976; // Valor default de primeira iteração
        // Fase de correção
        do
        {
            // Verifica-se se não é a primeira iteração
            if(Simais1Vk != -976 || Simais1Yk != -976)
            {
                Simais1V = Simais1Vk;
                Simais1Y = Simais1Yk;
            }
            Simais1Vk = v0 + (deltaT/24.0)*(Fvi2 -5*Fvi1 +19*Fvi +9*Fimais1BarraV);
            Simais1Yk = y0 + (deltaT/24.0)*(Fyi2 -5*Fyi1 +19*Fyi +9*Fimais1BarraY);
        }
        while(std::abs(Simais1Vk - Simais1V / Simais1Vk) < error && std::abs(Simais1Yk - Simais1Y / Simais1Yk) < error);
        
        //std::cout << "T = " << t0 + i*deltaT+ deltaT << std::endl;
        //std::cout << "V" << i << " : " << Simais1Vk << std::endl;
        //std::cout << "Y" << i << " : " << Simais1Yk << std::endl << std::endl;


        // Atualizando os valores para a próxima iteração
        v0 = Simais1Vk;
        y0 = Simais1Yk;

        Fvi3 = Fvi2;
        Fvi2 = Fvi1;
        Fvi1 = Fvi;
        Fvi = (-g-(k/m)*Simais1Vk);

        Fyi3 = Fyi2;
        Fyi2 = Fyi1;
        Fyi1 = Fyi;
        Fyi = Simais1Vk;

        // Verificação se o objeto chegou ao nível no mar, mostrando na tela quando isso ocorreu e com qual velocidade
        // Como raramente o objeto chega em exatamente 0, são mostrados os passos próximos a chegada do nivel do mar
        // Usei como padrão de aproximação o inteiro 1 já que consegue mostrar com precisão os passos até a chegada do mar
        // Esse valor poderá ser ajustado para mostrar mais ou menos iterações
        if( std::abs(y0) < 1 )
        {

            std::cout << "Passos relevantes quanto à queda no mar: " << std::endl;
            std::cout << "T = " << t0 + i*deltaT+ deltaT << std::endl;
            std::cout << "V" << i+1 << " : " << v0 << std::endl;
            std::cout << "Y" << i+1 << " : " << y0 << std::endl << std::endl;
        }

        if(maxY < y0)
        {
            maxY = y0;
            maxT = t0 + i*deltaT + deltaT;
            maxI = i+1;
        }
    }

    // Mostrando a altura máxima da trajetória e os dados referentes a esse passo
    std::cout << "Passo da altura máxima na trajetória: " << std::endl;
    std::cout << "T = " << maxT << std::endl;
    std::cout << "Y" << maxI << " : " << maxY << std::endl << std::endl;

}
