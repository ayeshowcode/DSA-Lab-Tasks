#include <iostream>
using namespace std;
class Solution
{
    int rows = 5, cols = 5;
    bool **arr = new bool *[5];
    bool temp[5][5] = {
        {true, true, true, false, false},
        {true, true, true, false, false},
        {true, false, true, false, true},
        {false, true, true, false, false},
        {true, true, false, false, true}};

public:
    Solution()
    {
        for (int i = 0; i < rows; i++)
        {
            arr[i] = new bool[cols];
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                arr[i][j] = temp[i][j];
            }
        }
    }
    void display()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << arr[i][j] << "  ";
            }
            cout << endl;
        }
    }
    bool haveCommonFriend(int i, int j)
    {
        for (int k = 0; k < rows; k++)
        {
            if (k != i && k != j && arr[i][k] && arr[j][k])
            {
                return true; // A common friend found
            }
        }
        return false; // No common friend found
    }
};
int main()
{
    Solution s;
    s.display();
    if (s.haveCommonFriend(2, 1))
        cout << "person 2 and person 1 have common friends";
    else
        cout << "person 2 and person 1 have no common friends";
}