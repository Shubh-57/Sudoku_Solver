#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int row, int col, vector<vector<int>> board, int val)
{
    for (int i = 0; i < 9; i++)
    {
        // Row Check
        if (board[row][i] == val)
        {
            return false;
        }
        // Column Check
        if (board[i][col] == val)
        {
            return false;
        }
        // 3x3 Matrix Check
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
        {
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<int>> &board)
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            // Empty Cell
            if (board[row][col] == 0)
            {
                for (int val = 1; val <= 9; val++)
                {
                    if (isSafe(row, col, board, val))
                    {
                        board[row][col] = val;
                        // Recursive Call
                        bool isSafeNext = solve(board);
                        if (isSafeNext)
                        {
                            return true;
                        }
                        else
                        {
                            // Backtracking
                            board[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

// T.C = O(9^m) (m = no. of empty cell)
// S.C = O(1)
void solveSudoku(vector<vector<int>> &sudoku)
{
    solve(sudoku);
}

int main()
{

    return 0;
}