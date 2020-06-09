#pragma once

#include <string>
#include <vector>
using std::string;

class Answer{
    private:
        double result;
        int iterations;
        double time;
        bool errorFlag;
        string errorMessage;
    
    public:
        Answer();
        
        // Para métodos que retornam um double
        Answer(double  result, int iterations, double time);
        // Para métodos que retornam autovetores e autovalores
        Answer(std::vector<double> eigenvector,double eigenvalue, int iterations, double time);

        Answer(string getErrorMessage);
        double getResult();
        int getIterations();
        double getTime();
        bool getErrorFlag();
        string getErrorMessage();
};
