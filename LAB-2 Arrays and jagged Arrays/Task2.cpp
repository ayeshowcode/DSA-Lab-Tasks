#include <iostream>
#include "matrix_multiply.h"
using namespace std;
int main()
{
    int row1 = 2, row2 = 2;
    int col1 = 2, col2 = 2;

    int **mat1 = new int *[row1];
    int **mat2 = new int *[row2];

    for (int i = 0; i < row1; i++)
    {
        mat1[i] = new int[col1];
    }
    for (int i = 0; i < row2; i++)
    {
        mat2[i] = new int[col2];
    }
    mat1[0][0]=1;
    mat1[0][1]=2;
    mat1[1][0]=3;
    mat1[1][1]=4;

    mat2[0][0]=5;
    mat2[0][1]=6;
    mat2[1][0]=7;
    mat2[1][1]=8;

    cout << "MATRIX 1:" << endl;
    for (int i = 0; i< row1; i++)
    {
        for (int j =0; j< col1; j++)
        {
            cout << mat1[i][j] << " ";
        }
        cout << endl;
    }
    cout << "MATRIX 2: " << endl;
    for (int i = 0; i< row2; i++)
    {
        for (int j = 0; j< col2; j++)
        {
            cout << mat2[i][j] << " "; 
        }
        cout << endl;
    }
    int **result=multiply_matrices(mat1, mat2, row1, col1, col2);
    cout<< "RESULT OF MAT 1 AND MAT 2"<< endl;
    for(int i = 0; i< row1; i++)
    {
        for (int j = 0; j< col1; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i< row1; i++)
    {
        delete mat1[i];
    }
    delete mat1;
    
    for (int i = 0; i< row2; i++)
    {
        delete mat2[i];
    }
    delete mat2;
    
}
