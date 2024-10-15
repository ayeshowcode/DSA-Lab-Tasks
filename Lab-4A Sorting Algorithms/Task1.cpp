#include <iostream>
using namespace std;
void bubbleSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (A[j] < A[j + 1])
            {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}
int main()
{
    int A[10] = {5,1,3,6,2,9,7,4,8,10};
    cout << "ORIGINAL" << endl;
    for (int i = 0; i < 10; i++)
        cout << A[i] << " ";
    bubbleSort(A, 10);
    cout << endl;
    cout << "SORTED" << endl;
    for (int i = 0; i < 10; i++)
        cout << A[i] << " ";
}