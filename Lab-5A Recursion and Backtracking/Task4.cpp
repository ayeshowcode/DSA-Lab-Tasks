#include <iostream>
using namespace std;

int sumOfJaggedArrayrec(int *arr[], int sizes[], int dim)
{
    if (dim == 0)
    {
        return 0;
    }
    int sum = 0;
    for (int i = 0; i < sizes[dim - 1]; i++)
    {
        sum += arr[dim - 1][i];
    }
    return sum + sumOfJaggedArrayrec(arr, sizes, dim - 1);
}

int main()
{
    int rows;
    cout << "Enter the no of rows: ";
    cin >> rows;

    int **arr = new int *[rows];
    int *nofelements = new int[rows];

    for (int i = 0; i < rows; i++)
    {
        cout << "Enter the number of elements in row " << i + 1 << ": ";
        cin >> nofelements[i];
        arr[i] = new int[nofelements[i]];
    }

    for (int i = 0; i < rows; i++)
    {
        cout << "Enter elements for row " << i + 1 << ": " << endl;
        for (int j = 0; j < nofelements[i]; j++)
        {
            cout << "Element number " << j + 1 << ": ";
            cin >> arr[i][j];
        }
    }

    cout << "Elements arr:" << endl;
    for (int i = 0; i < rows; i++)
    {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < nofelements[i]; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int sum = sumOfJaggedArrayrec(arr, nofelements, rows);
    cout << "Sum of all elements: " << sum << endl;

    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    delete[] nofelements;

    return 0;
}