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

// Aqui, definimos nossa função que será testada (a mesma presente na aula 8)
double fun( double x )
{
    return std::pow((std::sin(2*x) +(4*x*x) + 3*x), 2);
}


int main() 
{


    Integrate i;

    Answer gl2 = i.calculate_by_gauss_legendre_2( &fun, 0, 1, 1e-6, false);
    Answer gl3 = i.calculate_by_gauss_legendre_3( &fun, 0, 1, 1e-6, false);
    Answer gl4 = i.calculate_by_gauss_legendre_4( &fun, 0, 1, 1e-6, false);

    // Ajustando a precisão pra 6 casas decimais
    std::cout << std::fixed << std::setprecision(7) << std::endl;
    

    std::cout << "Integral Gauss Legendre 2 pontos: " << gl2.getResult() << std::endl;
    std::cout << "Iterações: " << gl2.getIterations() << std::endl<< std::endl;
    
    std::cout << "Integral Gauss Legendre 3 pontos: " << gl3.getResult() << std::endl;
    std::cout << "Iterações: " << gl3.getIterations() << std::endl<< std::endl;

    std::cout << "Integral Gauss Legendre 4 pontos: " << gl4.getResult() << std::endl;
    std::cout << "Iterações: " << gl4.getIterations() << std::endl<< std::endl;
    return 0;

}

