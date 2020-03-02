#pragma once

#include <string>
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
        Answer(double  result, int iterations, double time);
        Answer(string getErrorMessage);
        double getResult();
        int getIterations();
        double getTime();
        bool getErrorFlag();
        string getErrorMessage();
};
