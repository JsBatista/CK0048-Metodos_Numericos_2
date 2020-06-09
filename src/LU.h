#pragma once
#include "Answer.h"
#include <vector>

class LU{
    private:
        bool isTriangularMatrix(std::vector<std::vector<double>> A);

    public:
        LU();

        void truncate(double &x);
        void choose_pivot(std::vector<std::vector<double>> A, int k, double &pv, int &r);
};