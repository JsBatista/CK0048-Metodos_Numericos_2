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
    

    // Automatização: Definindo o número de partições
    int N = 8;

    // Automatização: Definindo deltaX e deltaY
    double deltaX = 1.0/N;
    double deltaY = 1.0/N;

    // Automatização: Calculando o número de icógnitas no problema bidimensional:
    int variables = (N-1)*(N-1);

    // Automatização: Nos casos que F(x,y) = C, definir esse C
    double C = 4;


    // Calculando matriz 49x4 IN
    std::vector<std::vector<double>> IN = {};
    for(int i = 0; i < variables; i++){
        IN.push_back({-1, -1, -1, -1});
    }    

    // Percorrendo matriz IN ajustando cada valor para condizer com a máscara:
    
    for(int i = 0; i < variables; i++){
        // Calculando Esquerda
        // Valores múltiplos de N estão na borda
        if( i % (N-1) != 0){
            IN[i][0] = i-1;
        }
        // Calculando Direita
        // Valores + 1 múltiplos de N estão na borda
        if( (i+1) % (N-1) != 0 ){
            IN[i][1] = i+1;
        }
        // Calculando Baixo
        // A primeira fila está na borda
        if( i >= (N-1) ){
            IN[i][2] = i-(N-1);
        }
        // Calculando Cima 
        // A ultima fila está na borda
        if( i < variables-(N-1) ){
            IN[i][3] = i+(N-1);
        }
    } 
    // Caso precise inspecionar IN
    Eigenvectors eigen;
    eigen.printMatrix(IN);

    // Matriz dos coeficientes da máscara
    std::vector<double> Mask = {1.0/(deltaX*deltaX), 1.0/(deltaX*deltaX), 1.0/(deltaY*deltaY), 1.0/(deltaY*deltaY)};
    double A = -2*(1.0/(deltaX*deltaX) + 1.0/(deltaY*deltaY));

    eigen.printVector(Mask);
    std::cout << "A: " << A;


    std::vector<std::vector<double>> SystemMatrix = {};
    for(int i = 0; i < variables; i++){
        SystemMatrix.push_back({});
        for(int j = 0; j < variables; j++){
            SystemMatrix[i].push_back(0);
        }
    }
    

    // Percorrer IN
    for(int i = 0; i < variables; i++){
        // Setar SystemMatrix[i][i] = A
        SystemMatrix[i][i] = A;
        // Automatização: NÃO MEXA NESSE 4, NÃO É IGUAL AO C
        for(int j = 0; j < 4; j ++){
            if(IN[i][j] != -1){
                SystemMatrix[i][IN[i][j]] = Mask[j];
            }
        }
    }
    
    eigen.printMatrix(SystemMatrix);

    // Criar vetor b:
    std::vector<double> b = {};
    for(int i = 0; i < variables; i++){
        // Automatização: Caso necessário, trocar C por execução de uma função F(x,y)
        b.push_back(C);
    }

    // Usando método de LU
    LU lu;
    std::vector<double> result = lu.LU_partial_pivoting(SystemMatrix, b);
    std::cout << "[ " << std::endl;
    for(int i = 0; i < variables; i++){
        std::cout << result[i] << " ," << std::endl;
    }
    std::cout << "] " << std::endl;

    return 0;

}

