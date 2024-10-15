#include <iostream>
using namespace std;

void printSolution(int **solution, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int **maze, int x, int y, int N)
{
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

bool solveMazeUtil(int **maze, int x, int y, int N, int **solution)
{
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1)
    {
        solution[x][y] = 1;
        return true;
    }

    if (isSafe(maze, x, y, N))
    {
        solution[x][y] = 1;

        if (solveMazeUtil(maze, x + 1, y, N, solution))
        {
            return true;
        }

        if (solveMazeUtil(maze, x, y + 1, N, solution))
        {
            return true;
        }
        solution[x][y] = 0;
        return false;
    }

    return false;
}

bool solveMaze(int **maze, int N)
{
    int **solution = new int *[N];
    for (int i = 0; i < N; i++)
    {
        solution[i] = new int[N];
        for (int j = 0; j < N; j++)
        {
            solution[i][j] = 0;
        }
    }

    if (!solveMazeUtil(maze, 0, 0, N, solution))
    {
        cout << "No solution exists." << endl;
        return false;
    }
    cout << endl;

    printSolution(solution, N);

    for (int i = 0; i < N; i++)
    {
        delete[] solution[i];
    }
    delete[] solution;

    return true;
}

int main()
{
    int N;
    cout << "Enter the size of the maze: ";
    cin >> N;

    int **maze = new int *[N];
    cout << "Enter the maze (1 for open, 0 for blocked):" << endl;
    for (int i = 0; i < N; i++)
    {
        maze[i] = new int[N];
        for (int j = 0; j < N; j++)
        {
            cin >> maze[i][j];
        }
    }

    solveMaze(maze, N);

    for (int i = 0; i < N; i++)
    {
        delete[] maze[i];
    }
    delete[] maze;

    return 0;
}
