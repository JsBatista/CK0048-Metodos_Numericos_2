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
        void fakePermute(std::vector<std::vector<double>> &A, int k, int r);
        void permute(std::vector<std::vector<double>> &A, std::vector<int> &p, int k, int r);
        void permute(std::vector<double> &b, std::vector<int> &p, int k, int r);
};