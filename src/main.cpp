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

double fun2( double x )
{
    return x*x + 2*x + 1;
}

int main() 
{


    Integrate i;

    Answer gh2 = i.calculate_by_gauss_hermite( &fun2, 2);
    Answer gh3 = i.calculate_by_gauss_hermite( &fun2, 3);
    Answer gh4 = i.calculate_by_gauss_hermite( &fun2, 4);

    Answer gl2 = i.calculate_by_gauss_laguerre( &fun2, 2);
    Answer gl3 = i.calculate_by_gauss_laguerre( &fun2, 3);
    Answer gl4 = i.calculate_by_gauss_laguerre( &fun2, 4);


    // Ajustando a precisão pra 6 casas decimais
    std::cout << std::fixed << std::setprecision(7) << std::endl;
    

    std::cout << "Integral Gauss Hermite 2 pontos: " << gh2.getResult() << std::endl;
    std::cout << "Integral Gauss Hermite 3 pontos: " << gh3.getResult() << std::endl;
    std::cout << "Integral Gauss Hermite 4 pontos: " << gh4.getResult() << std::endl << std::endl;
    std::cout << "Integral Gauss Laguerre 2 pontos: " << gl2.getResult() << std::endl;
    std::cout << "Integral Gauss Laguerre 3 pontos: " << gl3.getResult() << std::endl;
    std::cout << "Integral Gauss Laguerre 4 pontos: " << gl4.getResult() << std::endl;
    return 0;

}

