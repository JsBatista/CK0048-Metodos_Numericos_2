// Necessários para manipuilação de saída do terminal
#include <iostream>
#include <iomanip>
// Arquivos do programa
#include "Answer.h"
#include "Integrate.h"
// Necessário para funções matemáticas (nesse arquivo é a seno e a potencia)
#include <math.h>
// Necessário para manipulação de Strings
#include <string>
#include <functional>

// Aqui, definimos nossa função que será testada (a mesma presente na aula 8)
double fun( double x )
{
    return std::pow((std::sin(2*x) +(4*x*x) + 3*x), 2);
}

double fun2( double x )
{
    return 1/(std::sqrt(x));
}

double fun3( double x )
{
    return 1/(std::pow(x*x, 1.0/3.0));
}
double fun4( double x )
{
    return 1/(std::sqrt(4 - x*x));
}

int main() 
{
    // Ajustando a precisão pra 6 casas decimais
    std::cout << std::fixed << std::setprecision(7) << std::endl;


    Integrate i;

    Answer pt1 = i.calculate_by_singularity_nc(&fun3, -1, 0, 4, false);
    Answer pt2 = i.calculate_by_singularity_nc(&fun3, 0, 1, 4, false);

    std::cout << "Somando: " << pt1.getResult() + pt2.getResult() << std::endl;
    std::cout << "x2: " << 2*pt2.getResult() << std::endl;

    Answer gt1 = i.calculate_by_singularity_nc(&fun4, -2, 0, 4, true);
    Answer gt2 = i.calculate_by_singularity_nc(&fun4, -2, 0, 4, false);

    std::cout << "Simples: " << gt1.getResult() << std::endl;
    std::cout << "C: " << gt1.getIterations() << std::endl << std::endl;
    std::cout << "Duplo: " << gt2.getResult() << std::endl;
    std::cout << "C: " << gt2.getIterations() << std::endl;


    
    /*
    std::cout << "Integral por Singularidade Simples n = 2: " << ss1.getResult() << std::endl;
    std::cout << "Integral por Singularidade Simples n = 3: " << ss2.getResult() << std::endl;
    std::cout << "Integral por Singularidade Simples n = 4: " << ss3.getResult() << std::endl;
    std::cout << "Integral por Singularidade Dupla n = 2: " << sd1.getResult() << std::endl;
    std::cout << "Integral por Singularidade Dupla n = 3: " << sd2.getResult() << std::endl;
    std::cout << "Integral por Singularidade Dupla n = 4: " << sd3.getResult() << std::endl;
    */





        
    return 0;

}

