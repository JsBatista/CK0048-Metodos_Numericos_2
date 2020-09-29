// Necessários para manipuilação de saída do terminal
#include <iostream>
#include <iomanip>
// Arquivos do programa
#include "Answer.h"
#include "Integrate.h"
#include "Eigenvectors.h"
#include "OnePointBoundary.h"
// Necessário para funções matemáticas (nesse arquivo é a seno e a potencia)
#include <math.h>
// Necessário para manipulação de Strings
#include <string>
#include <functional>
// Necessário para manipulação de vetores
#include <vector>



int main() 
{

    OnePointBoundary opb;

    // Padrão e resolvido no PDF => Colisão com o nível do mar aos 16.3s
    // opb.eulerExplicitProblem1(163, 3, 150, 0.5, 0.5, 0.1, 0);
    // opb.rungeKuttaProblem(200, 3, 150, 0.5, 0.5, 0.1, 0);
    // opb.predictorCorrector(200, 3, 150, 0.5, 0.5, 0.1, 0, 0.000001);
    
    return 0;

}

