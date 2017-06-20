#include <stdio.h>
#include <stdlib.h>

struct matrix
{
    int row, col;
    int **data;
};

matrix multi(matrix A, matrix B)
{
    if(A.col == B.row)
    {

        matrix result;
        result.row = A.row;
        result.col = B.col;
        result.data = new int*[result.row];
        for(int i = 0; i < result.row; i++)
        {
            result.data[i] = new int[result.col];
            for(int j = 0; j < result.col; j++)
            {
                result.data[i][j] = 0;
                for(int k = 0; k < A.col; k++)
                {
                    result.data[i][j] += A.data[i][k] * B.data[k][j];
                }
            }
        }
        return result;
    }
}

void print(matrix A)
{
    printf("MATRIX: \n");
    for(int i = 0; i < A.row; i++)
    {
        for(int j = 0; j < A.col; j++)
        {
            printf("%d ", A.data[i][j]);
        }
        printf("\n");
    }
}

void del(matrix &A)
{
    delete[]A.data;
    for(int i = 0; i < A.row; i++)
    {
        delete[]A.data[i];
    }
}

matrix create_rand()
{
    matrix A;
    A.row = 2;
    A.col = 2;
    A.data = new int *[A.row];
    for(int i = 0; i < A.row; i++)
    {
        A.data[i] = new int[A.col];
        for(int j = 0; j < A.col; j++)
        {
            A.data[i][j] = rand() % 4;
        }
    }
    return A;
}

int main()
{
    matrix A, B;
    A = create_rand();
    B = create_rand();
    print(A);
    print(B);
    matrix C=multi(A,B);
    print(C);
    del(A);
    del(B);
    return 0;
}
