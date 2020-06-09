#include "Eigenvectors.h"
#include <iostream>
#include <math.h>

Eigenvectors::Eigenvectors(){

}

void Eigenvectors::printVector(std::vector<double> v)
{
	std::cout << "( ";
	for(uint i = 0; i < v.size(); i++)
	{
		std::cout << v[i];
		if(i != v.size()-1)
		{
			std::cout << ", ";
		}
	}
	std::cout << " )" << std::endl;
}

std::vector<double> Eigenvectors::normalizeVector(std::vector<double> v)
{

	double norm = 0;
	std::vector<double> normalizedV = v;

	for(uint i = 0; i < v.size(); i++)
	{
		norm += v[i]*v[i];
	}

	norm = std::sqrt(norm);

	for(uint i = 0; i < v.size(); i++)
	{
		normalizedV[i] = v[i]/norm;
	}
	return normalizedV;

}

std::vector<double> Eigenvectors::vectorMatrixMultiplication(std::vector<double> v, std::vector<std::vector<double>> A){
	std::vector<double> mult = v;

	double sum;

	for(uint i = 0; i < A.size(); i++)
	{
		sum = 0;
		for(uint j = 0; j < A[i].size(); j++)
		{
			sum += A[i][j]*v[j];
		}	
		mult[i] = sum;
	}

	return mult;
}

double Eigenvectors::dotProduct(std::vector<double> v1, std::vector<double> v2)
{
	double sum = 0;

	for(uint i = 0; i < v1.size(); i ++)
	{
		sum += v1[i]*v2[i];
	}

	return sum;
}

Answer Eigenvectors::calculateByRegularPower(std::vector<std::vector<double>> A, std::vector<double> v0, double error)
{


	// Passo 2
	double lambdaNew = 0;
	double lambdaOld;



	// Passo 3
	std::vector<double> vkNew = v0;
	std::vector<double> vkOld;
	std::vector<double> x1Old;	

	// Inicialização do laço para passos 4 à 9
	do
	{
		// Passo 4
		lambdaOld = lambdaNew;
		// Passo 5
		vkOld = vkNew;
		// Passo 6
		x1Old = Eigenvectors::normalizeVector(vkOld);

		// Passo 7
		vkNew = Eigenvectors::vectorMatrixMultiplication(x1Old, A);

		// Passo 8
		lambdaNew = Eigenvectors::dotProduct(x1Old, vkNew);

	} // Passo 9
	while( std::abs((lambdaNew - lambdaOld)/lambdaNew) > error );
	
	std::cout << "Autovalor: " << lambdaNew << std::endl;
	std::cout << "Autovetor: ";
	Eigenvectors::printVector(x1Old);
	std::cout << std::endl;



	return Answer();
	//return Answer(lambdaNew, x1Old, 0, 0);

}