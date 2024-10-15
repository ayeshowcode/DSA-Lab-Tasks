#include <iostream>
using namespace std;

int searchInsert(int nums[], int target, int n)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (target > nums[mid])
        {
            low = mid + 1;
        }
        else if (target < nums[mid])
        {
            high = mid - 1;
        }
        else
            return mid;
    }
    return low; 
}

int binarySearch(int nums[], int target, int n)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (target < nums[mid])
        {
            high = mid - 1;
        }
        else if (target > nums[mid])
        {
            low = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1; // Target not found
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int A[], int n)
{
    int i, j, k;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if (A[j] < A[k])
                k = j;
        }
        swap(&A[i], &A[k]);
    }
}

void insert(int A[], int &n, int x, int index, int capacity)
{
    if (n < capacity) 
    {
        for (int i = n; i > index; i--)
        {
            A[i] = A[i - 1];
        }
        A[index] = x;
        n++; 
    }
    else
    {
        cout << "Array is full, cannot insert new element." << endl;
    }
}

int main()
{
    const int capacity = 11;
    int rollno = 93; 
    int size = 10;
    int A[capacity] = {12, 45, 31, 12, 33, 12, 21, 54, 23, 1};

    selectionSort(A, size);

    cout << "Sorted array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    int index = binarySearch(A, rollno, size);
    if (index == -1)
    {
        index = searchInsert(A, rollno, size);
        insert(A, size, rollno, index, capacity);

        cout << "Array after insertion: " << endl;
        for (int i = 0; i < size; i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Element found at index: " << index << endl;
    }

    return 0;
}
