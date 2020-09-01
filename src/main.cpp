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

    // Padrão e resolvido no PDF
    // opb.eulerExplicitProblem1(163, 3, 150, 0.5, 0.5, 0.1, 0);

    // Explícito
    // Com deltaT = 0.1 => Altura máxima: 201.451 em T = 0.5 Passo 5
    //                     Queda no mar: Entre 7.8 e 7.9 s Entre passos 78 e 79 com Velocidade entre -48.1351 e -48.5334

    // Com deltaT = 0.01 => Altura Máxima: 201.225m em T = 0.49 Passo 49
    //                     Queda no mar: Entre 7.79 e 7.8 Entre passos 779 e 780 com Velocidade entre -47.9181 e -47.9582
    
    // Com deltaT = 0.001 => Altura Máxima: 201.203 em T = 0.485 Passo 485
    //                     Queda no mar: Entre T = 7.79 e T = 7.791 Entre passos 7790 e 7791 com Velocidade entre -47.9005 e -47.9045     
   
    // Com deltaT = 0.0001 => Altura Máxima: 201.2 em T = 0.485 Passo 4850
    //                     Queda no mar: Entre T = 7.7897  e T = 7.7898  Entre passos 77897 e 77898 com Velocidade entre -47.8975 e -47.8979 
    
    
    // Implícito
    // Com deltaT = 0.1 => Altura máxima: 200.963 em T = 0.4 Passo 4
    //                     Queda no mar: Entre T = 7.7 e T = 7.8 Entre passos 77 e 78 com Velocidade entre -47.3411 e -47.7493
    // Com deltaT = 0.01 => Altura máxima: 201.176 em T = 0.48 Passo 48
    //                     Queda no mar: Entre T = 7.78 e T = 7.79 Entre passos 778 e 779 com Velocidade entre -47.8389 e -47.8791
    // Com deltaT = 0.001 => Altura máxima: 201.198 em T = 0.485 Passo 485
    //                     Queda no mar: Entre T = 7.789 e T = 7.79 Entre passos 7789 e 7790 com Velocidade entre -47.8926 e -47.8966 
    // Com deltaT = 0.0001 => Altura máxima: 201.2 em T = 0.485 Passo 4850
    //                     Queda no mar: Entre T = 7.7897 e T = 7.7898 Entre passos 77897 e 77898 com Velocidade entre -47.8971 e -47.8976
    
    opb.eulerImplicitProblem1(163000, 5, 200, 0.25, 2, 0.0001, 0);

    return 0;

}

