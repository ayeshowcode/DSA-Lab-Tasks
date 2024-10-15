#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

bool isUniformlyDistributed(int arr[], int n)
{
    if (n < 2)
        return true;
    int diff = arr[1] - arr[0];
    for (int i = 2; i < n; ++i)
    {
        if (arr[i] - arr[i - 1] != diff)
        {
            return false;
        }
    }
    return true;
}

int interpolationSearch(int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;

    while (low <= high && target >= arr[low] && target <= arr[high])
    {
        if (low == high)
        {
            if (arr[low] == target)
                return low;
            return -1;
        }

        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (target - arr[low]));

        if (arr[pos] == target)
        {
            return pos;
        }

        if (arr[pos] < target)
        {
            low = pos + 1;
        }
        else
        {
            high = pos - 1;
        }
    }
    return -1;
}

int main()
{
    const int SIZE = 10;
    int arr[SIZE] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    int n = SIZE;
    int target = 70;

    bubbleSort(arr, n);

    if (!isUniformlyDistributed(arr, n))
    {
        cout << "Error: Data is not uniformly distributed." << endl;
        return 1;
    }

    int result = interpolationSearch(arr, n, target);
    if (result != -1)
    {
        cout << "Element found at index " << result << endl;
    }
    else
    {
        cout << "Element not found." << endl;
    }

    return 0;
}
