#include <iostream>
#include <vector>

using namespace std;

void print_board(vector<vector<int>> board){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<board[i][j]<<"  ";
        }
        cout<<endl;
    }
}

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
        // 3x3 Sub-matrix Check
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
        {
            return false;
        }
    }
    return true;
}

bool solveSudoku(vector<vector<int>> &board)
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
                        bool isSafeNext = solveSudoku(board);
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

int main()
{
    vector<vector<int>> board(9);

    board ={{5, 3, 0, 0, 7, 0, 0, 0, 0},
            {6, 0, 0, 1, 9, 5, 0, 0, 0},
            {0, 9, 8, 0, 0, 0, 0, 6, 0},
            {8, 0, 0, 0, 6, 0, 0, 0, 3},
            {4, 0, 0, 8, 0, 3, 0, 0, 1},
            {7, 0, 0, 0, 2, 0, 0, 0, 6},
            {0, 6, 0, 0, 0, 0, 2, 8, 0},
            {0, 0, 0, 4, 1, 9, 0, 0, 5},
            {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    cout<<"Before solved :"<<endl;
    print_board(board);
    cout<<endl;

    bool isPossible;
    isPossible = solveSudoku(board);

    if(isPossible){
        cout<<"After solved :"<<endl;
        print_board(board);
    }
    else{
        cout<<"It can't be solved";
    }

    return 0;
}
