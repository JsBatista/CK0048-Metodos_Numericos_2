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

    std::vector<std::vector<double>> B = {
        {3,1,0,0,0},
        {1,4,3,0,0},
        {0,3,5,2,1},
        {0,0,2,6,1},
        {0,0,1,3,8}
    };

    // Inicializando nosso objeto de cálculo de autovetores e autovalores
    Eigenvectors av;
    av.HouseholderMethod(A);
    //av.printMatrix(av.HouseholderMethodAux(B, 2));
    return 0;

}

