#include <iostream>
using namespace std;

int partition(int A[], int l, int h)
{
    int mid = l + (h - l)/2;
    int i = l + 1;
    int j = h;
    swap(A[l], A[mid]);
    int pivot = A[l];
    while (true)
    {
        while (i <= h && A[i] <= pivot)
        {
            i++;
        }
        while (j >= l && A[j] > pivot)
        {
            j--;
        }
        if (i >= j)
        {
            break;
        }
        swap(A[i], A[j]);
    }
    swap(A[l], A[j]);
    return j;
}
void quickSort(int A[], int l, int h)
{
    if (l < h)
    {
        int j = partition(A, l, h);
        quickSort(A, l, j - 1);
        quickSort(A, j + 1, h);
    }
}
int main()
{
    int size = 8;
    int *A = new int[size];
    for(int i = 0; i< size; i++)
    cin >> A[i];

    quickSort(A, 0, size - 1);

    for (int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }

    delete[] A;
    return 0;
}
