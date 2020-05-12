void add_matrices(int **C, int **A, int **B, int A_rows, int A_cols, int B_rows, int B_cols){
    for (int i = 0; i < A_cols; i++){
        for (int j = 0; j < B_rows; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtract_matrices(int **C, int **A, int **B, int A_rows, int A_cols, int B_rows, int B_cols){
    for (int i = 0; i < A_cols; i++){
        for (int j = 0; j < B_rows; j++){
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}


/**
 * Regular matrix multiplication algorithm when multiplication is done by A.rows * B.cols
 * @param C: Array of pointers where answer multiplication will be put in
 * @param A: A matrix to be multiplied
 * @param B: B matrix to be multplied
 * @param A_rows: Num of rows of A
 * @param A_cols: Num of cols of A
 * @param B_rows: Num of rows of B
 * @param B_cols: Num of cols of B
 */
void regular_multiplication(int **C, int **A, int **B, int A_rows, int A_cols, int B_rows, int B_cols)
{
    // If columns of A are different of rows of B, matrix multiplication can't be done, return
    if (A_cols != B_rows)
        return;
    for (int i = 0; i < A_rows; i++)
    {
        for (int j = 0; j < B_cols; j++)
        {
            // Reset sum in case C isn't initialised to 0
            C[i][j] = 0;
            for (int k = 0; k < A_cols; k++)
            {
                // Accum partial multiplications
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
}


/**
 * Matrix multiplication taking advantage of space locality of data in memory. Multiply rows by rows, instead of
 * rows by columns
 * @param C: Array of pointers where answer multiplication will be put in
 * @param A: A matrix to be multiplied
 * @param B: B matrix to be multplied
 * @param A_rows: Num of rows of A
 * @param A_cols: Num of cols of A
 * @param B_rows: Num of rows of B
 * @param B_cols: Num of cols of B
 */
void mult_with_space_locality(int **C, int **A, int **B, int A_rows, int A_cols, int B_rows, int B_cols)
{
    // If columns of A are different of rows of B, matrix multiplication can't be done, return
    if (A_cols != B_rows)
        return;

    // Create temp matrix to hold transpose of B
    int **B_transpose = new int *[B_cols];

    for (int i = 0; i < B_cols; i++)
    {
        B_transpose[i] = new int[B_rows];
    }
    // Compute transpose of B
    for(int i = 0; i < B_rows; i++){
        for(int j = 0; j < B_cols; j++){
            B_transpose[j][i] = B[i][j];
        }
    }
    // Multiply taking advantage of how data is actually stored in memory
    for (int i = 0; i < A_rows; i++)
    {
        for (int j = 0; j < B_cols; j++)
        {
            // Reset sum in case C isn't initialised to 0
            C[i][j] = 0;
            for (int k = 0; k < A_cols; k++)
            {
                // Accum partial multiplications
                C[i][j] += A[i][k]*B_transpose[j][k];
            }
        }
    }
}

void strassen(int **C, int **A, int **B, int A_rows, int A_cols, int B_rows, int B_cols)
{


}
