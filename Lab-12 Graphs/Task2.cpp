#include <iostream>
using namespace std;

// Directions for the 8 possible neighbors
int rNbr[] = {1, -1, 0, 0, 1, -1, 1, -1};
int cNbr[] = {0, 0, 1, -1, 1, -1, -1, 1};

// DFS function to mark the connected land as visited
void DFSIslands(char grid[50][50], int row, int col, int ROW, int COL)
{
    if (row < 0 || col < 0 || row >= ROW || col >= COL || grid[row][col] != '1')
    {
        return; // Out of bounds or already visited
    }

    // Mark the current cell as visited
    grid[row][col] = '0';

    // Traverse all 8 possible neighbors
    for (int i = 0; i < 8; i++)
    {
        DFSIslands(grid, row + rNbr[i], col + cNbr[i], ROW, COL);
    }
}

// Function to count the number of islands in the grid
int countIslands(char grid[50][50], int ROW, int COL)
{
    int count = 0;

    // Traverse the entire grid
    for (int r = 0; r < ROW; r++)
    {
        for (int c = 0; c < COL; c++)
        {
            if (grid[r][c] == '1')
            {                                     // If the cell is land
                count++;                          // Increment the island count
                DFSIslands(grid, r, c, ROW, COL); // Perform DFS to mark the connected land
            }
        }
    }

    return count;
}

int main()
{
    // Input grid dimensions
    int ROW, COL;
    char grid[50][50];

    cout << "Enter the number of rows in the grid: ";
    cin >> ROW;
    cout << "Enter the number of columns in the grid: ";
    cin >> COL;

    // Input the grid from the user
    cout << "Enter the grid (0 for water, 1 for land):" << endl;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            cin >> grid[i][j];
        }
    }

    // Count and display the number of islands
    cout << "\nNumber of islands in the grid: " << countIslands(grid, ROW, COL) << endl;

    return 0;
}