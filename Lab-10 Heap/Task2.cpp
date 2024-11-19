#include <iostream>
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

    // Destructor
    ~Heap()
    {
        delete[] arr;
    }

    // Helper functions
    int parent(int i) { return (i - 1) / 2; }
    int lchild(int i) { return (2 * i + 1); }
    int rchild(int i) { return (2 * i + 2); }

    // Min-Heapify
    void minHeapify(int i)
    {
        int l = lchild(i);
        int r = rchild(i);
        int smallest = i;

        if (l < heapSize && arr[l] < arr[smallest])
            smallest = l;
        if (r < heapSize && arr[r] < arr[smallest])
            smallest = r;

        if (smallest != i)
        {
            int temp = arr[i];
            arr[i] = arr[smallest];
            arr[smallest] = temp;

            minHeapify(smallest);
        }
    }

    // Max-Heapify
    void maxHeapify(int i)
    {
        int l = lchild(i);
        int r = rchild(i);
        int largest = i;

        if (l < heapSize && arr[l] > arr[largest])
            largest = l;
        if (r < heapSize && arr[r] > arr[largest])
            largest = r;

        if (largest != i)
        {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;

            maxHeapify(largest);
        }
    }

    // Build Min-Heap
    void buildMinHeap(int *inputArr, int size)
    {
        heapSize = size;
        for (int i = 0; i < size; i++)
            arr[i] = inputArr[i];

        for (int i = parent(size - 1); i >= 0; i--)
            minHeapify(i);
    }

    // Build Max-Heap
    void buildMaxHeap()
    {
        for (int i = parent(heapSize - 1); i >= 0; i--)
            maxHeapify(i);
    }

    // Remove Min
    void removeMin()
    {
        if (heapSize <= 0)
            return;
        if (heapSize == 1)
        {
            heapSize--;
            return;
        }

        arr[0] = arr[heapSize - 1];
        heapSize--;
        minHeapify(0);
    }

    // Sort the tree (Max-Heap)
    void sortHeap()
    {
        while (heapSize > 0)
        {
            cout << arr[0] << " ";
            arr[0] = arr[heapSize - 1];
            heapSize--;
            maxHeapify(0);
        }
        cout << endl;
    }

    // Print heap
    void printHeap()
    {
        for (int i = 0; i < heapSize; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// Main function
int main()
{
    int inputArr[] = {35, 33, 42, 10, 14, 19, 27, 44, 26, 31};
    int n = sizeof(inputArr) / sizeof(inputArr[0]);

    Heap h(n);

    cout << "Building Min-Heap..." << endl;
    h.buildMinHeap(inputArr, n);
    h.printHeap();

    cout << "Removing root node from Min-Heap..." << endl;
    h.removeMin();
    h.printHeap();

    cout << "Rebalancing tree to Max-Heap..." << endl;
    h.buildMaxHeap();
    h.printHeap();

    cout << "Sorting tree (Max-Heap)..." << endl;
    h.sortHeap();

    return 0;
}