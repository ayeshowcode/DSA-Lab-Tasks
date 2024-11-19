#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

class Heap
{
    int *arr;     // Pointer to the heap array
    int maxSize;  // Maximum size of the heap
    int heapSize; // Current number of elements in the heap

public:
    // Constructor
    Heap(int totSize)
    {
        heapSize = 0;
        maxSize = totSize;
        arr = new int[totSize];
    }

    // Helper functions
    int parent(int i)
    {
        return (i - 1) / 2;
    }
    int lchild(int i)
    {
        return (2 * i + 1);
    }
    int rchild(int i)
    {
        return (2 * i + 2);
    }

    void maxHeapify(int i)
    {
        int l = lchild(i);
        int r = rchild(i);
        int largest = i;

        if (l < heapSize && arr[l] > arr[i])
            largest = l;
        if (r < heapSize && arr[r] > arr[largest])
            largest = r;

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            maxHeapify(largest);
        }
    }

    void minHeapify(int i)
    {
        int l = lchild(i);
        int r = rchild(i);
        int smallest = i;

        if (l < heapSize && arr[l] < arr[i])
            smallest = l;
        if (r < heapSize && arr[r] < arr[smallest])
            smallest = r;

        if (smallest != i)
        {
            swap(arr[i], arr[smallest]);
            minHeapify(smallest);
        }
    }

    void buildMaxHeap(int *inputArr, int size)
    {
        heapSize = size;
        for (int i = 0; i < size; i++)
        {
            arr[i] = inputArr[i];
        }

        for (int i = parent(size - 1); i >= 0; i--)
        {
            maxHeapify(i);
        }
    }

    void buildMinHeap(int *inputArr, int size)
    {
        heapSize = size;
        for (int i = 0; i < size; i++)
        {
            arr[i] = inputArr[i];
        }

        for (int i = parent(size - 1); i >= 0; i--)
        {
            minHeapify(i);
        }
    }


    void printHeap()
    {
        if (heapSize == 0)
        {
            cout << "Heap is empty." << endl;
            return;
        }

        cout << "Heap elements: ";
        for (int i = 0; i < heapSize; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Main function
int main()
{
    Heap h(15);

    cout << "Building max heap from array {7,1,6,2,5,9,10,2}..." << endl;
    int inputArr[] = {7,1,6,2,5,9,10,2};
    h.buildMaxHeap(inputArr, 8);
    h.printHeap();

    cout << "Building min heap from array {7,1,6,2,5,9,10,2}..." << endl;
    h.buildMinHeap(inputArr, 8);
    h.printHeap();

    return 0;
}
