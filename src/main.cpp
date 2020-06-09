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
    
    std::vector<double> vetor1 = {1,2,3,4,5};

    std::vector<std::vector<double>> A = {
        {40, 8, 4, 2, 1},
        {8, 30, 12, 6, 2},
        {4, 12, 20, 1, 2},
        {2, 6, 1, 25, 4},
        {1, 2, 2, 4, 5}
    };

    Eigenvectors av;

    Answer resp = av.calculateByRegularPower(A, vetor1);

	std::cout << "Autovalor: " << resp.getEigenvalue() << std::endl;
	std::cout << "Autovetor: ";
	av.printVector(resp.getEigenvector());
	std::cout << std::endl;

    return 0;

}

