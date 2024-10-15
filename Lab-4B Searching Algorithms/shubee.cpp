#include <iostream>
using namespace std;
int BinarySearch(int arr[], int n, int key)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }

        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
void Selectionsort(int arr[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        int index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[index] > arr[j])
            {
                index = j;
            }
        }

        if (index != i)
        {
            int temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;
        }
    }
}

int main()
{

    int size;
    cout << "Enter No of Employees : ";
    cin >> size;
    int empIDS[size + 1]; 

    for (int i = 0; i < size; i++)
    {
        cout << "Employee " << i + 1 << " ID : ";
        cin >> empIDS[i];
    }

    int rollNum = 53; 

    Selectionsort(empIDS, size);

    if (BinarySearch(empIDS, size, rollNum) == -1)
    {

        int i = size - 1;
        while (i >= 0 && empIDS[i] > rollNum)
        {
            empIDS[i + 1] = empIDS[i];
            i--;
        }
        empIDS[i + 1] = rollNum;
        size++;

        cout << "Roll Num inserted SuccessFully " << endl;
    }
    else
        cout << "No Insertion Required" << endl;

    cout << "Employee IDs: ";
    for (int i = 0; i < size; i++)
    {
        cout << empIDS[i] << " ";
    }
    cout << endl;
}
