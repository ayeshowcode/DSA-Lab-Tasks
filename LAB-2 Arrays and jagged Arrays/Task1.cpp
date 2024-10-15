#include <iostream>
using namespace std;
int main()
{
    int **jaggedArray = new int *[5];
    int initialSize = 5;
    for (int i = 0; i < initialSize; i++)
    {
        jaggedArray[i] = new int[initialSize];
    }
    int newSize = 10;
    // initial array 5X5
    for (int i = 0; i < initialSize; i++)
    {
        for (int j = 0; j < initialSize; j++)
        {
            jaggedArray[i][j]=0;
            cout << jaggedArray[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl
         << endl;
    // RESIZING
    for (int i = 0; i < initialSize; i++)
    {
        int *temp = new int[newSize];
        for (int j = 0; j < newSize; j++)
        {
            temp[i] = jaggedArray[i][j];
        }
        delete[] jaggedArray[i];
        jaggedArray[i] = temp;
    }
    // INPUT FOR THE RESIZED ARRAY 5X10
    cout << "Enter elements for each row (10 elements per row):\n";
    for (int i = 0; i < initialSize; i++)
    {
        for (int j = 0; j < newSize; j++)
        {
            cout << "Enter element for row " << i + 1 << ", column " << j + 1 << ": ";
            cin >> jaggedArray[i][j];
        }
    }
    cout << "Array element are: \n";
    // DISPLAYING
    for (int i = 0; i < initialSize; i++)
    {
        for (int j = 0; j < newSize; j++)
        {
            cout << jaggedArray[i][j] << " ";
        }
        cout << endl;
    }
}