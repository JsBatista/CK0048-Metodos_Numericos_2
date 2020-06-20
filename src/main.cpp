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


    // Inicializando nosso objeto de cálculo de autovetores e autovalores
    Eigenvectors av;

    std::vector<std::vector<double>> A2t = av.transpostMatrix(A2);

    av.printMatrix(av.matrixMatrixMultiplication(A2, A3));


    return 0;

}

