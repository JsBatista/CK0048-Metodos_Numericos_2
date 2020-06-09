#pragma once
#include "Answer.h"
#include <vector>

class Eigenvectors
{

	private:
		std::vector<double> normalizeVector(std::vector<double> v);
		std::vector<double> vectorMatrixMultiplication(std::vector<double> v, std::vector<std::vector<double>> A);
		double dotProduct(std::vector<double> v1, std::vector<double> v2);
		bool isSquareMatrix(std::vector<std::vector<double>> A);


	public:
		Eigenvectors();		
		void printVector(std::vector<double> v);
		void printMatrix(std::vector<std::vector<double>> A);
		Answer calculateByRegularPower(std::vector<std::vector<double>> A, std::vector<double> v0, double error = 0.000001);
};