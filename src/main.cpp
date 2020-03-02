#include <iostream>
#include "Answer.h"

int main() 
{

    Answer r(1,2,3);

    std::cout << "Hello World!" << std::endl;
    std::cout << r.getResult() << std::endl << r.getIterations() << std::endl << r.getTime() << std::endl;
    return 0;

}

