#pragma once
#include "Answer.h"
#include <vector>

class Eigenvectors
{

	private:
		std::vector<double> normalizeVector(std::vector<double> v);
		std::vector<double> vectorMatrixMultiplication(std::vector<double> v, std::vector<std::vector<double>> A);
		double dotProduct(std::vector<double> v1, std::vector<double> v2);


	public:
		Eigenvectors();		
		void printVector(std::vector<double> v);
		Answer calculateByRegularPower(std::vector<std::vector<double>> A, std::vector<double> v0, double error = 0.000001);
};