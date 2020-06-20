// Necessários para manipuilação de saída do terminal
#include <iostream>
#include <iomanip>
// Arquivos do programa
#include "Answer.h"
#include "Integrate.h"
#include "Eigenvectors.h"
// Necessário para funções matemáticas (nesse arquivo é a seno e a potencia)
#include <math.h>
// Necessário para manipulação de Strings
#include <string>
#include <functional>
// Necessário para manipulação de vetores
#include <vector>



int main() 
{

    std::vector<std::vector<double>> A = {
        {40, 8, 4, 2, 1},
        {8, 30, 12, 6, 2},
        {4, 12, 20, 1, 2},
        {2, 6, 1, 25, 4},
        {1, 2, 2, 4, 5}
    };

    // Matriz 2
    std::vector<std::vector<double>> A2 = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    std::vector<std::vector<double>> A3 = {
        {10, 11,12},
        {13,14,15},
        {16,17,18}
    };

    std::vector<std::vector<double>> v = {{1,2,3}};


    // Inicializando nosso objeto de cálculo de autovetores e autovalores
    Eigenvectors av;
    av.HouseholderMethod(A);
    std::cout << "OK";
    return 0;

}

