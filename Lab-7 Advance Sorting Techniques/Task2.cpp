#include <iostream>
using namespace std;

int getMax(int* arr, int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

void countingSortAscending(int* arr, int n, int exp) {
    int* output = new int[n];
    int count[10] = {0};      

    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    delete[] output;  
}

void countingSortDescending(int* arr, int n, int exp) {
    int* output = new int[n];  
    int count[10] = {0};       

    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    for (int i = 8; i >= 0; i--) {
        count[i] += count[i + 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    delete[] output;  
}

void radixSortAscending(int* arr, int n) {
    int maxVal = getMax(arr, n);  

    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSortAscending(arr, n, exp);
    }
}

void radixSortDescending(int* arr, int n) {
    int maxVal = getMax(arr, n);  

    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSortDescending(arr, n, exp);
    }
}

void printArray(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int* arr = new int[n]; 

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Array in Ascending Order: ";
    radixSortAscending(arr, n);
    printArray(arr, n);

    cout << "Array in Descending Order: ";
    radixSortDescending(arr, n);
    printArray(arr, n);

    delete[] arr; 
    return 0;
}
