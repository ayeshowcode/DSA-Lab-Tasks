#include <iostream>
using namespace std;
void shellSort(int A[], int n)
{
    int gap, i, j, temp;
    for (gap = n / 3; gap >= 1; gap /= 3)
    {
        for (i = gap; i < n; i++)
        {
            temp = A[i];
            j = i - gap;
            while (j >= 0 && A[j] > temp)
            {
                A[j + gap] = A[j];
                j = j - gap;
            }
            A[j + gap] = temp;
        }
    }
}
int main()
{
    int size;
    cout << "Enter the no of weighs: ";
    cin >> size;
    int *weights = new int[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter weight no: " << i + 1 << ": ";
        cin >> weights[i];
    }
    cout << "before shell sort" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << weights[i] << " ";
    }
    shellSort(weights, size);
    cout << endl;
    cout << "After shell sort" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << weights[i] << " ";
    }
}