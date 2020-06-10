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

// Resolve um sistema de equações por Iterações Retroativas
std::vector<double> LU::retroativeIterations(std::vector<std::vector<double>> A, std::vector<double> b)
{
    // Cria e inicializa o vetor solução com N zeros
    std::vector<double> x;
    for(uint i = 0; i < b.size(); i++)
    {
        x.push_back(0);
    }

    // Resolve o ultimo X da solução através de uma simples divisão 
    x[b.size()-1] = b[A.size()-1] / A[A.size()-1][A.size()-1];
    
    // Itera sobre a matriz, linha por linha, calculando os Xs da resposta
    double sum;
    for(int i =  A.size() - 2; i >= 0; i --)
    {
        sum = 0;
        for(uint j = i+1; j < A.size(); j++)
        {
            sum += A[i][j] * x[j];
        }    
        // Registra o valor calculado no vetor solução X
        x[i] = (b[i] - sum) / A[i][i];
    }

    return x;
}

// Resolve um sistema de equações por Iterações Sucessivas
std::vector<double> LU::sucessiveIterations(std::vector<std::vector<double>> A, std::vector<double> b)
{
    // Cria e inicializa o vetor solução com N zeros
    std::vector<double> x;
    for(uint i = 0; i < b.size(); i++)
        x.push_back(0);

    // Itera sobre a matriz, linha por linha, calculando os Xs da resposta
    double sum;

    for(uint i = 0; i < b.size(); i++){
        sum = 0;
        for(uint j = 0; j < i; j++)
        {
            sum += A[i][j]*x[j];
        }
        // Registra o valor calculado no vetor solução X
        x[i] = b[i] - sum;
    }

    return x;    
}

Answer LU::LU_partial_pivoting(std::vector<std::vector<double>> A, std::vector<double> b)
{
	std::vector<int> p;
    std::vector<std::vector<double>> L;
    std::vector<std::vector<double>> U;

    for(uint i = 0; i < A.size(); i++)
    {
        L.push_back({});
        U.push_back({});
        for(uint j = 0; j < A.size(); j++)
        {
            L[i].push_back(0);
            U[i].push_back(0);
        }
    }

    for(uint i = 0; i < b.size(); i++)
        p.push_back(i);
    
    for(int k = 0; k < int(b.size()); k++)
    {
        double pivot;
        int r;
        LU::choose_pivot(A, k, pivot, r);

        if(pivot == 0)
            return Answer("A matriz é singular!");
        
        if(k != r){
            LU::permute(A, p, k, r);
            LU::fakePermute(L, k, r);
        }
        double m;
        for(int i = 0; i < k+1; i++)
        {
            U[i][k] = A[i][k];
        }
        for(uint i = k+1; i < b.size(); i++)
        {
            m = A[i][k]/A[k][k];
            LU::truncate(m);
            A[i][k] = m;
            L[i][k] = m;
            for(uint j = k+1; j < b.size(); j++)
            {
                A[i][j] = A[i][j] - m*A[k][j]; 
                LU::truncate(A[i][j]);
            }
        }
    }
    std::vector<double> blin;
    int r;
    for(uint i = 0; i < b.size(); i++)
    {
        r = p[i];
        blin.push_back(b[r]);
    }

    std::vector<double> y = LU::sucessiveIterations(A, blin);
    std::vector<double> x = LU::retroativeIterations(A, y);
    return Answer(x, 0.0, 0,  0.0);
}


std::vector<std::vector<std::vector<double>>> LU::LU_factoration(std::vector<std::vector<double>> A)
{	

	std::vector<int> p;
    std::vector<std::vector<double>> L;
    std::vector<std::vector<double>> U;

    for(uint i = 0; i < A.size(); i++)
    {
        L.push_back({});
        U.push_back({});
        for(uint j = 0; j < A.size(); j++)
        {
            L[i].push_back(0);
            U[i].push_back(0);
        }
    }

    for(uint i = 0; i < A.size(); i++)
        p.push_back(i);
    
    for(int k = 0; k < int(A.size()); k++)
    {
        double pivot;
        int r;
        LU::choose_pivot(A, k, pivot, r);

        if(pivot == 0)
            return {{},{}};
        
        if(k != r){
            LU::permute(A, p, k, r);
            LU::fakePermute(L, k, r);
        }
        double m;
        for(int i = 0; i < k+1; i++)
        {
            U[i][k] = A[i][k];
        }
        for(uint i = k+1; i < A.size(); i++)
        {
            m = A[i][k]/A[k][k];
            LU::truncate(m);
            A[i][k] = m;
            L[i][k] = m;
            for(uint j = k+1; j < A.size(); j++)
            {
                A[i][j] = A[i][j] - m*A[k][j]; 
                LU::truncate(A[i][j]);
            }
        }
    }

    return {L,U};
}