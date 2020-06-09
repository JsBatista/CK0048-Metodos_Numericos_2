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