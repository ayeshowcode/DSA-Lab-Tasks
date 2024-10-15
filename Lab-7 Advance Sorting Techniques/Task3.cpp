#include <iostream>
using namespace std;

// Merging two sorted subarrays A[l...m] and A[m+1...r]
void mergeasc(int A[], int l, int m, int r)
{
    int n1 = m - l + 1; // Size of left subarray
    int n2 = r - m;     // Size of right subarray

    // Create temporary arrays
    int *L = new int [n1];
    int *R = new int [n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = A[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[m + 1 + j];

    // Initial indexes of L[], R[], and merged array
    int i = 0, j = 0, k = l;

    // Merge the temporary arrays back into A[l...r]
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[] (if any)
    while (i < n1)
    {
        A[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[] (if any)
    while (j < n2)
    {
        A[k] = R[j];
        j++;
        k++;
    }
}
void mergedesc(int A[], int l, int m, int r)
{
    int n1 = m - l + 1; // Size of left subarray
    int n2 = r - m;     // Size of right subarray

    // Create temporary arrays
    int *L = new int [n1];
    int *R = new int [n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = A[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[m + 1 + j];

    // Initial indexes of L[], R[], and merged array
    int i = 0, j = 0, k = l;

    // Merge the temporary arrays back into A[l...r]
    while (i < n1 && j < n2)
    {
        if (L[i] >= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[] (if any)
    while (i < n1)
    {
        A[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[] (if any)
    while (j < n2)
    {
        A[k] = R[j];
        j++;
        k++;
    }
}

// MergeSort function to sort the array A[l...r]
void mergeSortasc(int A[], int l, int r)
{
    if (l >= r)
        return; // Base case: array of size 1 is already sorted

    int m = l + (r - l) / 2; // Middle point

    // Sort the left half
    mergeSortasc(A, l, m);

    // Sort the right half
    mergeSortasc(A, m + 1, r);

    // Merge the sorted halves
    mergeasc(A, l, m, r);
}
void mergeSortdesc(int A[], int l, int r)
{
    if (l >= r)
        return; // Base case: array of size 1 is already sorted

    int m = l + (r - l) / 2; // Middle point

    // Sort the left half
    mergeSortdesc(A, l, m);

    // Sort the right half
    mergeSortdesc(A, m + 1, r);

    // Merge the sorted halves
    mergedesc(A, l, m, r);
}

int main()
{
    int size;
    cout << "Entet the no of elements: ";
    cin >> size;
   int *A= new int [size];
   for(int i = 0; i< size; i++)
   {
    cin >> A[i];
   }
    cout << "Given array: ";
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;

    mergeSortasc(A, 0, size - 1); // Sort the array
    cout << "Ascending array: ";
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
    mergeSortdesc(A, 0, size - 1); // Sort the array
    cout << "Descending array: ";
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;


    return 0;
}
