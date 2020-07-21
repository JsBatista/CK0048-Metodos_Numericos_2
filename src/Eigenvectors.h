#pragma once
#include "Answer.h"
#include <vector>

class Eigenvectors
{

	private:
		double getNorm(std::vector<double> v);
		std::vector<double> vectorMatrixMultiplication(std::vector<double> v, std::vector<std::vector<double>> A);
		double dotProduct(std::vector<double> v1, std::vector<double> v2);
		bool isSquareMatrix(std::vector<std::vector<double>> A);
		std::vector<double> vectorSubtraction(std::vector<double> v1, std::vector<double> v2);
		std::vector<std::vector<double>> matrixSubtraction(std::vector<std::vector<double>> A, std::vector<std::vector<double>> B);
		std::vector<std::vector<double>> truncateMatrix(std::vector<std::vector<double>> A);





	public:
		Eigenvectors();		
		void printVector(std::vector<double> v);
		void printMatrix(std::vector<std::vector<double>> A);
		std::vector<std::vector<double>> transpostMatrix(std::vector<std::vector<double>> A);
		std::vector<std::vector<double>> matrixMatrixMultiplication(std::vector<std::vector<double>> A,std::vector<std::vector<double>> B);
		std::vector<double> vectorScalarMultiplication(std::vector<double> v, double x);
		std::vector<std::vector<double>> matrixScalarMultiplication(std::vector<std::vector<double>> A, double x);
		std::vector<std::vector<double>> createMatrix(int n, bool i);

		std::vector<double> normalizeVector(std::vector<double> v);
		Answer calculateByRegularPower(std::vector<std::vector<double>> A, std::vector<double> v0, double error = 0.000001);
		Answer calculateByInversePower(std::vector<std::vector<double>> A, std::vector<double> v0, double error = 0.000001);
		Answer calculateByDisplacementPower(std::vector<std::vector<double>> A, std::vector<double> v0, double u, double error = 0.000001);

		void HouseholderMethod(std::vector<std::vector<double>> A);
		std::vector<std::vector<double>> HouseholderMethodAux(std::vector<std::vector<double>> A, int i);

		void JacobiMethod(std::vector<std::vector<double>> A, int n, double error);
		std::vector<std::vector<std::vector<double>>> JacobiSweep(std::vector<std::vector<double>> A, int n);
		std::vector<std::vector<double>> JacobiMatrixIJBased(std::vector<std::vector<double>> A, int i, int j, int n);
};