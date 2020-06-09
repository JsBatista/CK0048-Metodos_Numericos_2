#include "LU.h"
#include <iostream>
#include <math.h>

// Construtor padrão
LU::LU()
{

}

bool LU::isTriangularMatrix(std::vector<std::vector<double>> A)
{
    for(uint column = 0; column < A.size(); column++)
    {
        for(uint row = 0; row < column; row++)
        {
            std::cout <<  A[column][row] << std::endl;
            if(A[column][row] != 0)
            {
                return false;
            }
        }
        std::cout << std::endl;
    }
    return true;
}

void LU::truncate(double &x)
{
    if(std::fabs(x) < 1e-6)
        x = 0;
}


void LU::choose_pivot(std::vector<std::vector<double>> A, int k, double &pv, int &r)
{

    double pivot = std::fabs(A[k][k]);
    // Se o elemento da diagonal atual for o pivô real, vamos mantê-lo como pivô
    pv = A[k][k];
    // O mesmo para o seu índice
    r = k;

    // Fazemos a busca em toda matriz A
    for(uint i = k+1; i < A.size(); i++)
    {
        // Se acharmos alguém maior que o pivô
        if( std::fabs(A[i][k]) > pivot )
        {
            // Atualizamos o pivô para ele
            pivot = std::fabs(A[i][k]);
            pv = A[i][k];
            // Fazemos o mesmo com o seu íncide
            r = i;
        }
    }
};

// Faz a permutação mas não registra nada no vetor de permutação
void LU::fakePermute(std::vector<std::vector<double>> &A, int k, int r)
{
    // Fazemos a permutação
    for(uint j = 0; j < A.size(); j++)
        std::swap(A[k][j], A[r][j]);
}


// Faz a permutação de duas linhas da matriz A e registra a troca no vetor de permutação p
void LU::permute(std::vector<std::vector<double>> &A, std::vector<int> &p, int k, int r){
    // Registra a troca no vetor de permutação
    std::swap(p[k], p[r]);

    // Fazemos a permutação
    for(uint j = 0; j < A.size(); j++)
        std::swap(A[k][j], A[r][j]);
}


// Faz a permutação no vetor b
void LU::permute(std::vector<double> &b, std::vector<int> &p, int k, int r)
{    
    // Registra a troca no array de permutação
    std::swap(p[k], p[r]);

    // Troca os elementos no vetor b
    std::swap(b[k], b[r]);
}