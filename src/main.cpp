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

	// Calculamos todas as integrais
	// Usamos o erro como 1e-6 e debug como falso para desativar os couts durante a execução    
    Answer a = i.calculate_by_newton_cotes_deg_1_closed( &fun, 0, 1, 1e-6, false);
    Answer b = i.calculate_by_newton_cotes_deg_2_closed( &fun, 0, 1, 1e-6, false);
    Answer c = i.calculate_by_newton_cotes_deg_3_closed( &fun, 0, 1, 1e-6, false);
    Answer d = i.calculate_by_newton_cotes_deg_4_closed( &fun, 0, 1, 1e-6, false);
    Answer e = i.calculate_by_newton_cotes_deg_1_open( &fun, 0, 1, 1e-6, false);
    Answer f = i.calculate_by_newton_cotes_deg_2_open( &fun, 0, 1, 1e-6, false);
    Answer g = i.calculate_by_newton_cotes_deg_3_open( &fun, 0, 1, 1e-6, false);
    Answer h = i.calculate_by_newton_cotes_deg_4_open( &fun, 0, 1, 1e-6, false);

    // Ajustando a precisão pra 6 casas decimais
    std::cout << std::fixed << std::setprecision(6) << std::endl;

    // Imprimimos cada resultado
    std::cout << "Integral grau 1: " << a.getResult() << std::endl;
    std::cout << "Iterações: " << a.getIterations() << std::endl << std::endl;


    std::cout << "Integral grau 2: " << b.getResult() << std::endl;
    std::cout << "Iterações: " << b.getIterations() << std::endl<< std::endl;


    std::cout << "Integral grau 3: " << c.getResult() << std::endl;
    std::cout << "Iterações: " << c.getIterations() << std::endl<< std::endl;


    std::cout << "Integral grau 4: " << d.getResult() << std::endl;
    std::cout << "Iterações: " << d.getIterations() << std::endl<< std::endl;


    std::cout << "Integral grau 1 aberta: " << e.getResult() << std::endl;
    std::cout << "Iterações: " << e.getIterations() << std::endl<< std::endl;


    std::cout << "Integral grau 2 aberta: " << f.getResult() << std::endl;
    std::cout << "Iterações: " << f.getIterations() << std::endl<< std::endl;


    std::cout << "Integral grau 3 aberta: " << g.getResult() << std::endl;
    std::cout << "Iterações: " << g.getIterations() << std::endl<< std::endl;

    std::cout << "Integral grau 4 aberta: " << h.getResult() << std::endl;
    std::cout << "Iterações: " << h.getIterations() << std::endl<< std::endl;

    return 0;

}

