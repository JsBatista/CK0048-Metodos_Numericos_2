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

	// Inicializando nosso objeto de cálculo de autovetores e autovalores
    Eigenvectors av;

    // Calculando para a Matriz 1 por Potência Regular
    Answer resp1 = av.calculateByRegularPower(A1, chute1);

    // Calculando para a Matriz 2 por Potência Regular
    Answer resp2 = av.calculateByRegularPower(A2, chute2);

	std::cout << "_______________________________________________________________" << std::endl << "Matriz 1:" << std::endl << std::endl;	
    if(!resp1.getErrorFlag())
    {
	    std::cout << "Autovalor: " << resp1.getEigenvalue() << std::endl;
		std::cout << "Autovetor: ";
		av.printVector(resp1.getEigenvector());
		std::cout << "Iterações: " << resp1.getIterations() << std::endl << std::endl << std::endl;
    } else
    {
    	std::cout << "Um erro ocorreu ao executar o método!" << std::endl;
    	std::cout << resp1.getErrorMessage() << std::endl;
    }

    std::cout << "_______________________________________________________________" << std::endl << "Matriz 2:" << std::endl << std::endl;
    if(!resp2.getErrorFlag())
    {
		std::cout << "Autovalor: " << resp2.getEigenvalue() << std::endl;
		std::cout << "Autovetor: ";
		av.printVector(resp2.getEigenvector());
		std::cout << "Iterações: " << resp2.getIterations() << std::endl << std::endl << std::endl;
    } else
    {
    	std::cout << "Um erro ocorreu ao executar o método!" << std::endl;
    	std::cout << resp2.getErrorMessage() << std::endl;
    }

    return 0;

}

