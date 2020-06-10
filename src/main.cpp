// Necessários para manipuilação de saída do terminal
#include <iostream>
#include <iomanip>
// Arquivos do programa
#include "Answer.h"
#include "Integrate.h"
#include "Eigenvectors.h"
#include "LU.h"
// Necessário para funções matemáticas (nesse arquivo é a seno e a potencia)
#include <math.h>
// Necessário para manipulação de Strings
#include <string>
#include <functional>
// Necessário para manipulação de vetores
#include <vector>



int main() 
{
	// Vetores de chute    
    std::vector<double> chute1 = {1,2,3};
    std::vector<double> chute2 = {1,2,3,4,5};

    // Matriz 1
    std::vector<std::vector<double>> A1 = {
        {5,2,1},
        {2,3,1},
        {1,1,2}
    };

    // Matriz 2
    std::vector<std::vector<double>> A2 = {
        {40, 8, 4, 2, 1},
        {8, 30, 12, 6, 2},
        {4, 12, 20, 1, 2},
        {2, 6, 1, 25, 4},
        {1, 2, 2, 4, 5}
    };


    LU lu;
    Eigenvectors av;


    
    return 0;

}

