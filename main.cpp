#include <iostream>
#include <valarray>
#include "sorting_algorithms.h"
#include "matrices_mult.h"
/*
 * Documentation...
 * ...
 *
 */
using namespace std;

void Initialise(double **res, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            res[i][j] = i*j; // whatever you want.
        }
    }
}

int main() {
    int aRows = 10;
    int aCols = 5;
    int bRows = 5;
    int bCols = 6;
    // Array of pointers
    double** A = new double*[aRows];
    for (int i = 0; i < aRows; i++)
    {
        A[i] = new double[aCols];
    }

    double** B = new double*[bRows];
    for (int i = 0; i < bRows; i++)
    {
        B[i] = new double[bCols];
    }

    Initialise(A, aRows, aCols);
    Initialise(B, bRows, bCols);

    double** C;
    C = new double*[aRows];
    for (int i = 0; i < aRows; i++)
    {
        C[i] = new double [bCols];
    }

    regular_multiplication(C,A,B,aRows,aCols,bRows,bCols);

    for (int i = 0; i < aRows; i++)
    {
        for (int j = 0; j < bCols; j++)
        {
            std::cout << C[i][j] << ' ';
        }
        std::cout << '\n';
    }

    return 0;



}


