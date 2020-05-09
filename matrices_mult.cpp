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
void regular_multiplication(double **C, double **A, double **B, int A_rows, int A_cols, int B_rows, int B_cols)
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
