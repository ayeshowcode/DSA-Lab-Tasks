#include "matrix_multiply.h"
#include<iostream>
int** multiply_matrices(int** mat1, int** mat2, int rows1, int cols1, int cols2)
{
    int **result= new int*[rows1];
    for(int i = 0; i< rows1; i++)
    {
        result[i]= new int[cols2];
    }
    for (int i = 0; i< rows1; i++)
    {
        for (int j = 0; j< cols2; j++)
        {
            result[i][j]=0;
        }
    }
    for (int i = 0; i< rows1; i++)
    {
        for (int j = 0; j< cols2; j++)
        {
            for(int k = 0; k < cols1; k++)
            {
                result[i][j]+=mat1[i][k]*mat2[k][j];
            }
        }
    }
    return result;
}