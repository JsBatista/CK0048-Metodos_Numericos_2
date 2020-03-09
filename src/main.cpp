#include <iostream>
#include <vector>
#include "Answer.h"
#include "Derivatives.h"
#include <math.h>
#include <string>

double sin_fun( double x )
{
    return std::sin(x);
}

int main() 
{


    const double pi = 3.1415926535897;

    Derivatives d;

    Answer a = d.calculate_second_forward(&sin_fun, pi/3, 0.1);
    Answer b = d.calculate_second_backwards(&sin_fun, pi/3, 0.1);
    Answer c = d.calculate_second_central(&sin_fun, pi/3, 0.1);



    std::cout << "Derivada segunda real: " << (-1)*std::sin(pi/3) << std::endl << std::endl; 

    std::cout << "Derivada segunda aproximada Forward: " << a.getResult() << std::endl;
    std::cout << "Derivada segunda aproximada Forward: " << b.getResult() << std::endl;
    std::cout << "Derivada segunda aproximada Central: " << c.getResult() << std::endl;





/*
    // Lets pretend we are reading the image matrix here for now
    std::vector< std::vector<double> > image = {
        {10.0, 10.0, 20.0, 20.0, 20.0},
        {10.0, 10.0, 20.0, 20.0, 20.0},
        {10.0, 10.0, 20.0, 20.0, 20.0},
        {10.0, 10.0, 20.0, 20.0, 20.0},
        {10.0, 10.0, 20.0, 20.0, 20.0}
    };

    // Creating a 0s matrix with the same dimensions as the image we read

    std::vector< std::vector<double> > sobel_filtered_image;

    for(unsigned int i = 0; i < image.size(); i ++)
    {
        std::vector<double> to_be_added  = {};
        sobel_filtered_image.push_back( to_be_added );

        for(unsigned int j = 0; j < image[i].size(); j ++)
        {
            sobel_filtered_image[i].push_back( 0.0 );
        }
    }

    // Defining the sobel matrixes

    std::vector< std::vector< double > > sobel_matrix_y = {
        {(1.0/3.0), (1.0/3.0), (1.0/3.0) },
        {0, 0, 0 },
        {-(1.0/3.0), -(1.0/3.0), -(1.0/3.0)}
    };

    std::vector< std::vector< double > > sobel_matrix_x = {
        {-(1.0/3.0), 0, (1.0/3.0) },
        {-(1.0/3.0), 0, (1.0/3.0) },
        {-(1.0/3.0), 0, (1.0/3.0) }
    };



    // Trying to make the filtered X matrix

    for( unsigned int i = 1; i < sobel_filtered_image.size() - 1; i ++)
    {
        for( unsigned int j = 1; j < sobel_filtered_image.size() - 1; j++)
        {
            sobel_filtered_image[i][j] = 
                                         image[i-1][j-1]*sobel_matrix_x[0][0] +
                                         image[i][j-1]*sobel_matrix_x[1][0] +  
                                         image[i+1][j-1]*sobel_matrix_x[2][0] + 
                                         image[i-1][j+1]*sobel_matrix_x[0][2] + 
                                         image[i][j+1]*sobel_matrix_x[1][2] + 
                                         image[i+1][j+1]*sobel_matrix_x[2][2];    
        }
    }   

    // Printing the null matrix

    for(unsigned int i = 0; i < sobel_filtered_image.size(); i ++)
    {   
        std::string line = "";
        for(unsigned int j = 0; j < sobel_filtered_image[i].size(); j ++)
        {
            line = line + std::to_string(sobel_filtered_image[i][j])  + " ";
        }

        std::cout << line << std::endl;
    }
*/
    return 0;

}

