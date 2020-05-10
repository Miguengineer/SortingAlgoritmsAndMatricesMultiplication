#include <iostream>
#include <valarray>
#include "sorting_algorithms.h"
#include "matrices_mult.h"
#include "utils.h"
/*
 * Documentation...
 * ...
 *
 */
using namespace std;

void Initialise(int **res, int rows, int cols)
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
    /*
    int aRows = 3;
    int aCols = 2;
    int bRows = 2;
    int bCols = 4;
    // Array of pointers
    int** A = new int*[aRows];
    for (int i = 0; i < aRows; i++)
    {
        A[i] = new int[aCols];
    }

    int** B = new int*[bRows];
    for (int i = 0; i < bRows; i++)
    {
        B[i] = new int[bCols];
    }

    Initialise(A, aRows, aCols);
    Initialise(B, bRows, bCols);

    int** C;
    C = new int*[aRows];
    for (int i = 0; i < aRows; i++)
    {
        C[i] = new int [bCols];
    }

    mult_with_space_locality(C,A,B,aRows,aCols,bRows,bCols);

    for (int i = 0; i < aRows; i++)
    {
        for (int j = 0; j < bCols; j++)
        {
            std::cout << C[i][j] << ' ';
        }
        std::cout << '\n';
    }
    */
    test_insertionsort();

    return 0;



}


