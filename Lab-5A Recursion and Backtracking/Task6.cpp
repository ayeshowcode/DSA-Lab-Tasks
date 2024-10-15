#include <iostream>
using namespace std;

bool isSafe(int **board, int row, int col, int N)
{
    int i, j;

    for (i = 0; i < row; i++)
        if (board[i][col])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

void printSolution(int **board, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

bool placeFlags(int **board, int row, int N)
{
    if (row >= N)
        return true;

    for (int col = 0; col < N; col++)
    {
        if (isSafe(board, row, col, N))
        {
            board[row][col] = 1;

            if (placeFlags(board, row + 1, N))
                return true;

            board[row][col] = 0;
        }
    }

    return false;
}

void solve(int N)
{
    int **board = new int *[N];
    for (int i = 0; i < N; i++)
        board[i] = new int[N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    if (!placeFlags(board, 0, N))
        cout << "No solution exists." << endl;
    else
        printSolution(board, N);

    for (int i = 0; i < N; i++)
        delete[] board[i];
    delete[] board;
}

int main()
{
    int N;
    cout << "Enter the value of N (size of the board): ";
    cin >> N;
    solve(N);
    return 0;
}
