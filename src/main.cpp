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
    return 1/(std::sqrt(x));
}

int main() 
{


    Integrate i;


    Answer ss1 = i.calculate_by_singularity_gh(&fun2, 0, 1, 2, true);
    Answer ss2 = i.calculate_by_singularity_gh(&fun2, 0, 1, 3, true);
    Answer ss3 = i.calculate_by_singularity_gh(&fun2, 0, 1, 4, true);
    Answer sd1 = i.calculate_by_singularity_gh(&fun2, 0, 1, 2, false);
    Answer sd2 = i.calculate_by_singularity_gh(&fun2, 0, 1, 3, false);
    Answer sd3 = i.calculate_by_singularity_gh(&fun2, 0, 1, 4, false);


    // Ajustando a precisão pra 6 casas decimais
    std::cout << std::fixed << std::setprecision(7) << std::endl;
    

    std::cout << "Integral por Singularidade Simples n = 2: " << ss1.getResult() << std::endl;
    std::cout << "Integral por Singularidade Simples n = 3: " << ss2.getResult() << std::endl;
    std::cout << "Integral por Singularidade Simples n = 4: " << ss3.getResult() << std::endl;
    std::cout << "Integral por Singularidade Dupla n = 2: " << sd1.getResult() << std::endl;
    std::cout << "Integral por Singularidade Dupla n = 3: " << sd2.getResult() << std::endl;
    std::cout << "Integral por Singularidade Dupla n = 4: " << sd3.getResult() << std::endl;
    return 0;

}

