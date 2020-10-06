// Necessários para manipuilação de saída do terminal
#include <iostream>
#include <iomanip>
// Arquivos do programa
#include "Answer.h"
#include "Integrate.h"
#include "Eigenvectors.h"
#include "OnePointBoundary.h"
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

    OnePointBoundary opb;

    // Padrão e resolvido no PDF => Colisão com o nível do mar aos 16.3s
    // opb.eulerExplicitProblem1(163, 3, 150, 0.5, 0.5, 0.1, 0);
    // opb.rungeKuttaProblem(200, 3, 150, 0.5, 0.5, 0.1, 0);
    // opb.predictorCorrector(200, 3, 150, 0.5, 0.5, 0.1, 0, 0.000001);

    // Preciso questionar minha sanidade calculando um sistema de equações com 49 icógnitas
    

    // Calculando matriz 49x4 IN
    std::vector<std::vector<double>> IN = {};
    for(int i = 0; i < 49; i++){
        IN.push_back({-1, -1, -1, -1});
    }    

    // Percorrendo matriz IN ajustando cada valor para condizer com a máscara:
    for(int i = 0; i < 49; i++){
        // Calculando Esquerda
        // Valores múltiplos de 7 estão na borda
        if(i % 7 != 0){
            IN[i][0] = i-1;
        }
        // Calculando Direita
        // Valores + 1 múltiplos de 7 estão na borda
        if( (i+1) % 7 != 0 ){
            IN[i][1] = i+1;
        }
        // Calculando Baixo
        // A primeira fila está na borda
        if( i >= 7 ){
            IN[i][2] = i-7;
        }
        // Calculando Cima 
        // A ultima fila está na borda
        if( i <= 41 ){
            IN[i][3] = i+7;
        }
    } 
    // Caso precise inspecionar IN
    //Eigenvectors eigen;
    //eigen.printMatrix(IN);

    // Matriz dos coeficientes da máscara
    std::vector<double> Mask = {64, 64, 64, 64};
    double A = -256;


    std::vector<std::vector<double>> SystemMatrix = {};
    for(int i = 0; i < 49; i++){
        SystemMatrix.push_back({});
        for(int j = 0; j < 49; j++){
            SystemMatrix[i].push_back(0);
        }
    }

    // Percorrer IN
    for(int i = 0; i < 49; i++){
        // Setar SystemMatrix[i][i] = A
        SystemMatrix[i][i] = A;

        for(int j = 0; j < 4; j ++){
            if(IN[i][j] != -1){
                SystemMatrix[i][IN[i][j]] = Mask[j];
            }
        }
    }

    // Criar vetor b:
    std::vector<double> b = {};
    for(int i = 0; i < 49; i++){
        b.push_back(4);
    }

    // Usando método de LU
    LU lu;
    std::vector<double> result = lu.LU_partial_pivoting(SystemMatrix, b);
    std::cout << "[ " << std::endl;
    for(int i = 0; i < 49; i++){
        std::cout << result[i] << " ," << std::endl;
    }
    std::cout << "] " << std::endl;
    
    std::cout << std::endl<< std::endl<< result[8] << std::endl;
    std::cout << std::endl<< std::endl<< result[12] << std::endl;
    std::cout << std::endl<< std::endl<< result[36] << std::endl;
    std::cout << std::endl<< std::endl<< result[40] << std::endl;
    return 0;

}

