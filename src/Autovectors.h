#pragma once
#include "Answer.h"
#include <vector>

class Autovectors
{

	private:
		void printVector(std::vector<double> v);
		std::vector<double> normalizeVector(std::vector<double> v);
		std::vector<double> vectorMatrixMultiplication(std::vector<double> v, std::vector<std::vector<double>> A);
		double dotProduct(std::vector<double> v1, std::vector<double> v2);


	public:
		Autovectors();		
		Answer calculateByRegularPower(std::vector<std::vector<double>> A, std::vector<double> v0, double error = 0.000001);
};