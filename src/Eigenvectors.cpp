#include "Eigenvectors.h"
#include "LU.h"
#include <iostream>
#include <math.h>

// Construtor padrão
Eigenvectors::Eigenvectors(){

}

// Cria uma matriz nxn que pode ou não ser identidade
std::vector<std::vector<double>> Eigenvectors::createMatrix(int n, bool i)
{
	std::vector<std::vector<double>> M;
	for(int k = 0; k < n; k++)
	{
		M.push_back({});
		for(int j = 0; j < n; j++)
		{
			if(i && k == j)
				M[k].push_back(1);
			else
				M[k].push_back(0);

		}
	}
	return M;
}

// Trunca elementos da matrix em 6 casas decimais
std::vector<std::vector<double>> Eigenvectors::truncateMatrix(std::vector<std::vector<double>> A)
{
	std::vector<std::vector<double>> M;

	for(uint i = 0; i < A.size(); i ++)
	{
		M.push_back({});
		for(uint j = 0; j < A[0].size(); j++)
		{
			M[i].push_back(0);
		}
	}

	for(uint i = 0; i < A.size(); i++)
		for(uint j = 0; j < A[i].size(); j++)
			if(std::abs(A[i][j]) > 0.00000000001)
				M[i][j] = A[i][j];

	return M;
}


// Método que imprime um vetor, já que vector não é diretamente compatível com std::cout
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

// Método que imprime uma matriz, já que vector não é diretamente compatível com std::cout
void Eigenvectors::printMatrix(std::vector<std::vector<double>> A)
{
	std::cout << "[ " << std::endl;
	for(uint i = 0; i < A.size(); i++)
	{
		Eigenvectors::printVector(A[i]);
	}
	std::cout << " ]" << std::endl;
}



// Método que recebe um vetor e o normaliza, retornando o vetor normalizado
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

// Retorna a norma do vetor
double Eigenvectors::getNorm(std::vector<double> v)
{
	double norm = 0;
	std::vector<double> normalizedV = v;

	for(uint i = 0; i < v.size(); i++)
	{
		norm += v[i]*v[i];
	}

	return std::sqrt(norm);
}

// Retorna o vetor resultante da subtração v1 - v2
std::vector<double> Eigenvectors::vectorSubtraction(std::vector<double> v1, std::vector<double> v2)
{
	std::vector<double> s;

	for(uint i = 0; i < v1.size(); i++)
		s.push_back(v1[i] - v2[i]);

	return s;
}

// Retorna a matriz resultante da subtração A - B
std::vector<std::vector<double>> Eigenvectors::matrixSubtraction(std::vector<std::vector<double>> A, std::vector<std::vector<double>> B)
{
	std::vector<std::vector<double>> S;

	for(uint i = 0; i < A.size(); i++)
	{
		S.push_back({});
		for(uint j = 0; j < A[0].size(); j++)
		{
			S[i].push_back(A[i][j] - B[i][j]);
		}
	}

	return S;
}

// Método que realiza a multiplicação de um vetor por uma matriz, ou vice versa, contanto que ambos sejam compatíveis
// ex: Se a matrix for 5x3 e o vetor for 3x1, a multiplicação será feita Matriz x Vetor
//     Se a matriz for 5x3 e o vetor for 5x1, a multiplicação será feita Vetor x Matriz
// Como esse método só é usado de maneira controlada dentro do código que receberá uma matriz quadrada e um vetor de 
// tamanho compatível, qualquer outro caso resultará em um erro
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

// Multiplica 2 matrixes e retorna a matriz resultante
std::vector<std::vector<double>> Eigenvectors::matrixMatrixMultiplication(std::vector<std::vector<double>> A,std::vector<std::vector<double>> B)
{
	/*
	std::cout << "[BEGIN MATRIX MULTIPLICATION]" << std::endl;
	std::cout << "Multipling " << std::endl;
	Eigenvectors::printMatrix(A);
	std::cout<<" x " <<std::endl;
	Eigenvectors::printMatrix(B);
	*/
	std::vector<std::vector<double>> M;

	for(uint i = 0; i < A.size(); i ++)
	{
		M.push_back({});
		for(uint j = 0; j < B[0].size(); j++)
		{
			M[i].push_back(0);
		}
	}

	double sum;

	for(uint i = 0; i < A.size(); i ++)
	{
		for(uint j = 0; j < B[0].size(); j ++)
		{
			sum = 0;
			for(uint k = 0; k < B.size(); k ++)
			{
				sum += A[i][k] * B[k][j];
			}
			M[i][j] = sum;
		}
	}


	return M;
}

// Retorna o vetor resultante da multiplicação do vetor v1 pelo escalar x
std::vector<double> Eigenvectors::vectorScalarMultiplication(std::vector<double> v, double x)
{
	std::vector<double> m;

	for(uint i = 0; i < v.size(); i++)
		m.push_back(v[i]*x);

	return m;
}

std::vector<std::vector<double>> Eigenvectors::matrixScalarMultiplication(std::vector<std::vector<double>> A, double x)
{
	std::vector<std::vector<double>> M;

	for(uint i = 0; i < A.size(); i++)
	{
		M.push_back({});
		for(uint j = 0; j < A[0].size(); j++)
		{
			M[i].push_back(A[i][j]*x);
		}
	}

	return M;
}


// Faz o produto escalar de dois vetores de mesma dimensão
// Colocar dois vetores de dimensões diferentes irá resultar em um erro
// Usado apenas de maneira controlada em funções para evitar o erro
double Eigenvectors::dotProduct(std::vector<double> v1, std::vector<double> v2)
{
	double sum = 0;

	for(uint i = 0; i < v1.size(); i ++)
	{
		sum += v1[i]*v2[i];
	}

	return sum;
}

// Verifica se uma matriz é quadrada, retornando True ou False
bool Eigenvectors::isSquareMatrix(std::vector<std::vector<double>> A)
{
	uint tam = A.size();
	for(uint i = 0; i < tam; i++){
		if(A[i].size() != tam)
		{
			return false;
		}
	}
	return true;
}

// Retorna uma matriz transposta
std::vector<std::vector<double>> Eigenvectors::transpostMatrix(std::vector<std::vector<double>> A)
{
	std::vector<std::vector<double>> At;


	for(uint i = 0; i < A.size(); i++)
	{
		for(uint j = 0; j < A[i].size(); j++)
		{
			if(i == 0)
				At.push_back({A[i][j]});	
			else
				At[j].push_back(A[i][j]);
		}
	}
	return At;
}

// Calcula o Autovalor e o seu Autovetor associado pelo método da Potência Regular.
Answer Eigenvectors::calculateByRegularPower(std::vector<std::vector<double>> A, std::vector<double> v0, double error)
{
	// Fazemos algumas checagens de erro antes de progredir com o programa:
	if(!Eigenvectors::isSquareMatrix(A) )
	{
		return Answer("Dados de entrada não compatíveis com esse método! A matriz recebida deve ser quadrada!");
	}

	if(A.size() != v0.size())
	{
		return Answer("Dados de entrada não compatíveis com esse método! O vetor recebido não tem a mesma dimensão que as linhas e colunas da matriz recebida!");
	}

	// Inicializamos o contador
	uint cont = 0;

	// Passo 2 do algoritmo
	double lambdaNew = 0;
	double lambdaOld;

	// Passo 3 do algoritmo
	std::vector<double> vkNew = v0;

	// Inicializando Vk velho e X1 velho fora do laço para que seus valores não sejam sobrescritos nas iterações
	std::vector<double> vkOld;
	std::vector<double> x1Old;	

	// Inicialização do laço para passos 4 à 9
	do
	{	
		// Incremento do contador
		cont ++;
		// Passo 4 do algoritmo
		lambdaOld = lambdaNew;
		// Passo 5 do algoritmo
		vkOld = vkNew;
		// Passo 6 do algoritmo
		x1Old = Eigenvectors::normalizeVector(vkOld);
		// Passo 7 do algoritmo
		vkNew = Eigenvectors::vectorMatrixMultiplication(x1Old, A);
		// Passo 8 do algoritmo
		lambdaNew = Eigenvectors::dotProduct(x1Old, vkNew);

	} // Passo 9 do algoritmo (checagem de erro)
	while( std::abs((lambdaNew - lambdaOld)/lambdaNew) > error );

	// Retornando o Autovalor e o seu Autovetor associado
	return Answer(x1Old,lambdaNew, cont, 0);

}


Answer Eigenvectors::calculateByInversePower(std::vector<std::vector<double>> A, std::vector<double> v0, double error)
{
	// Fazemos algumas checagens de erro antes de progredir com o programa:
	if(!Eigenvectors::isSquareMatrix(A) )
	{
		return Answer("Dados de entrada não compatíveis com esse método! A matriz recebida deve ser quadrada!");
	}

	if(A.size() != v0.size())
	{
		return Answer("Dados de entrada não compatíveis com esse método! O vetor recebido não tem a mesma dimensão que as linhas e colunas da matriz recebida!");
	}

	LU lu;
	// Passo 2
	std::vector<std::vector<std::vector<double>>> lau = lu.LU_factoration(A);

	// Passo 3
	double lambda1New = 0;
	double lambda1Old;


	//Passo 4
	std::vector<double> vkNew = v0;
	std::vector<double> vkOld;
	std::vector<double> x1Old;
	
	// Inicializamos o contador
	uint cont = 0;

	do
	{
		// Incremento do contador
		cont ++;
		// Passo 5
		lambda1Old = lambda1New;
		// Passo 6
		vkOld = vkNew;
		// Passo 7
		x1Old = Eigenvectors::normalizeVector(vkOld);

		// Passo 8
		vkNew = lu.LU_partial_pivoting(A,x1Old);
		// Passo 9
		lambda1New = Eigenvectors::dotProduct(x1Old, vkNew);

	} while(std::abs((lambda1New - lambda1Old)/lambda1New) > error); // Passo 10 (checagem de erro)

	// Passo 11
	double lambdaN = 1/lambda1New;
	// Passo 12
	std::vector<double> xn = x1Old;

	// Retornando o Autovalor e o seu Autovetor associado
	return Answer(xn,lambdaN, cont, 0);
}


Answer Eigenvectors::calculateByDisplacementPower(std::vector<std::vector<double>> A, std::vector<double> v0, double u, double error)
{
	
	// Passo 1
	std::vector<std::vector<double>> Au = A;

	for(uint i = 0; i<A.size(); i++)
	{
		Au[i][i] = A[i][i] - u;
	}	
	// Passo 2
	Answer respostaInversa = Eigenvectors::calculateByInversePower(Au, v0, error);
	
	// Tratamento de erros
	if(respostaInversa.getErrorFlag())
		return Answer(respostaInversa.getErrorMessage());

	// Passo 3
	double lambda = respostaInversa.getEigenvalue() + u;
	// Passo 4
	std::vector<double> x = respostaInversa.getEigenvector();

	return Answer(x, lambda, respostaInversa.getIterations(), 0);
}


void Eigenvectors::HouseholderMethod(std::vector<std::vector<double>> A)
{
	std::vector<std::vector<double>> H, Hi, Ai, Abar, Aim1;
	
	// H = I
	for(uint i = 0; i < A.size(); i++)
	{
		H.push_back({});
		for(uint j = 0; j < A[i].size(); j++)
		{
			if(i == j)
				H[i].push_back(1);
			else
				H[i].push_back(0);
		}	
	}

	Aim1 = A;

	for(uint i = 0; i < A.size() -2 ; i++)
	{

		Hi = Eigenvectors::HouseholderMethodAux(Aim1, i);

		Ai = Eigenvectors::matrixMatrixMultiplication( Eigenvectors::matrixMatrixMultiplication( Eigenvectors::transpostMatrix(Hi), Aim1 ), Hi);
		
		Aim1 = Ai;

		Ai = Eigenvectors::truncateMatrix(Ai);
		Aim1 = Eigenvectors::truncateMatrix(Aim1);

		H = Eigenvectors::matrixMatrixMultiplication(H, Hi);
		H = Eigenvectors::truncateMatrix(H);
	}

	Abar = Ai;

	std::cout << std::endl << "(1)" << std::endl;
	std::cout << "Matriz A: " << std::endl;
	Eigenvectors::printMatrix(Abar);
	std::cout << "Matriz H: " << std::endl;
	Eigenvectors::printMatrix(H);


	Answer abar1 = Eigenvectors::calculateByDisplacementPower(Abar, {1,2,3,4,5}, 1);
	Answer abar2 = Eigenvectors::calculateByDisplacementPower(Abar, {1,2,3,4,5}, 10);
	Answer abar3 = Eigenvectors::calculateByDisplacementPower(Abar, {1,2,3,4,5}, 20);
	Answer abar4 = Eigenvectors::calculateByDisplacementPower(Abar, {1,2,3,4,5}, 30);
	Answer abar5 = Eigenvectors::calculateByDisplacementPower(Abar, {1,2,3,4,5}, 50);

	std::cout << std::endl << "(2)" << std::endl;
	std::cout << "Autovalores e Autovetores da matriz Abarra:" << std::endl;

	std::cout << std::endl << "Primeiro Autovalor: " << abar1.getEigenvalue() << std::endl;

	std::cout << "Autovetor relacionado: " << std::endl;
	Eigenvectors::printVector(abar1.getEigenvector());

	std::cout << std::endl << "Segundo Autovalor: " << abar2.getEigenvalue() << std::endl;

	std::cout << "Autovetor relacionado: " << std::endl;
	Eigenvectors::printVector(abar2.getEigenvector());

	std::cout << std::endl << "Terceiro Autovalor: " << abar3.getEigenvalue() << std::endl;

	std::cout << "Autovetor relacionado: " << std::endl;
	Eigenvectors::printVector(abar3.getEigenvector());

	std::cout << std::endl << "Quarto Autovalor: " << abar4.getEigenvalue() << std::endl;

	std::cout << "Autovetor relacionado: " << std::endl;
	Eigenvectors::printVector(abar4.getEigenvector());

	std::cout << std::endl << "Quinto Autovalor: " << abar5.getEigenvalue() << std::endl;

	std::cout << "Autovetor relacionado: " << std::endl;
	Eigenvectors::printVector(abar5.getEigenvector());

	std::cout <<std::endl<< "(3) & (4)" << std::endl << "Autovetores e Autovalores da matriz A:" << std::endl;

	std::cout << "Primeiro Autovalor: " << abar1.getEigenvalue() << std::endl;

	std::cout << "Autovetor relacionado: " << std::endl;
	Eigenvectors::printMatrix(
			Eigenvectors::matrixMatrixMultiplication(
					H, Eigenvectors::transpostMatrix({abar1.getEigenvector()})
				)
		);

	std::cout << "Segundo Autovalor: " << abar2.getEigenvalue() << std::endl;

	std::cout << "Autovetor relacionado: " << std::endl;
	Eigenvectors::printMatrix(
			Eigenvectors::matrixMatrixMultiplication(
					H, Eigenvectors::transpostMatrix({abar2.getEigenvector()})
				)
		);

	std::cout << "Terceiro Autovalor: " << abar3.getEigenvalue() << std::endl;

	std::cout << "Autovetor relacionado: " << std::endl;
	Eigenvectors::printMatrix(
			Eigenvectors::matrixMatrixMultiplication(
					H, Eigenvectors::transpostMatrix({abar3.getEigenvector()})
				)
		);

	std::cout << "Quarto Autovalor: " << abar4.getEigenvalue() << std::endl;

	std::cout << "Autovetor relacionado: " << std::endl;
	Eigenvectors::printMatrix(
			Eigenvectors::matrixMatrixMultiplication(
					H, Eigenvectors::transpostMatrix({abar4.getEigenvector()})
				)
		);

	std::cout << "Quinto Autovalor: " << abar5.getEigenvalue() << std::endl;

	std::cout << "Autovetor relacionado: " << std::endl;
	Eigenvectors::printMatrix(
			Eigenvectors::matrixMatrixMultiplication(
					H, Eigenvectors::transpostMatrix({abar5.getEigenvector()})
				)
		);
}


std::vector<std::vector<double>> Eigenvectors::HouseholderMethodAux(std::vector<std::vector<double>> A, int i)
{
	std::vector<std::vector<double>> I;
	
	for(uint j = 0; j < A.size(); j++)
	{
		I.push_back({});
		for(uint k = 0; k < A[j].size(); k++)
		{
			if(j == k)
				I[j].push_back(1);
			else
				I[j].push_back(0);
		}	
	}

	std::vector<double> w, wl, N, n, e;

	for(uint j = 0; j < A.size(); j ++)
	{
		w.push_back(0);
		wl.push_back(0);
		e.push_back(0);
	}
	for(uint x = i+1; x < A.size(); x++)
	{
		w[x] = A[x][i];
	}

	double Lw = Eigenvectors::getNorm(w);

	wl[i+1] = Lw;

	N = Eigenvectors::vectorSubtraction(w, wl);


	n = Eigenvectors::normalizeVector(N);
	

	std::vector<std::vector<double>> nMatrixForm = {n};

	std::vector<std::vector<double>> nMatrixFormT = Eigenvectors::transpostMatrix(nMatrixForm);


	std::vector<std::vector<double>> step1 = Eigenvectors::matrixMatrixMultiplication(nMatrixFormT, nMatrixForm);

	std::vector<std::vector<double>> step2 = Eigenvectors::matrixScalarMultiplication( step1,2);

	std::vector<std::vector<double>> H = Eigenvectors::matrixSubtraction(I, step2);

	return H;
}







// Iniciando método de Jacobi

void Eigenvectors::JacobiMethod(std::vector<std::vector<double>> A, int n, double error)
{

}
