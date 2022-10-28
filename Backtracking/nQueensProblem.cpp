#include <iostream>
using namespace std;

bool isSafe(int boards[][10], int i, int j, int n)
{
    // check for column
    for (int row = 0; row < i; row++)
    {
        if (boards[row][j] == 1)
            return false;
    }

    // check for left diagonal
    int x = i;
    int y = j;
    while (x >= 0 && y >= 0)
    {
        if (boards[x][y] == 1)
            return false;
        x--;
        y--;
    }

    // check for right diagonal
    x = i;
    y = j;
    while (x >= 0 && y < n)
    {
        if (boards[x][y] == 1)
            return false;
        x--;
        y++;
    }

    // now the postion is safe from columns and diagonals
    return true;
}



//all possible solution
bool solveNQueens(int boards[][10], int i, int n)
{
    // Base case
    if (i == n)
    {
        // You have successfully place queens in n rows(0 .... n-1)
        // Print the board
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (boards[i][j] == 1)
                {
                    cout << "Q"
                         << " ";
                }
                else
                {
                    cout << "_"
                         << " ";
                }
            }
            cout << endl;
        }
        cout << endl; 
        // if we want one possible solution we wil return true and if we want all possible solution we will return false
        return false;
    }

    // Recursive case
    // Try to place the queen in rows and call on the remaining part which wil be solved by recursion
    for (int j = 0; j < n; j++)
    {
        // check if i,j is safe to place the queen or not
        if (isSafe(boards, i, j, n))
        {
            // place the queen - Assuming i,j is the right position
            boards[i][j] = 1;
            bool nextQueenRakhPaye = solveNQueens(boards, i + 1, n);
            if (nextQueenRakhPaye)
            {
                return true;
            }

            // means i,j is not the right position - assumption is wrong
            boards[i][j] = 0; // backtrack
        }
    }
    // we have tried for all positions in the current row but could not placed the queen
    return false;
}



//one possible solution
bool solveNQueens1(int boards[][10], int i, int n)
{
    // Base case
    if (i == n)
    {
        // You have successfully place queens in n rows(0 .... n-1)
        // Print the board
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (boards[i][j] == 1)
                {
                    cout << "Q"
                         << " ";
                }
                else
                {
                    cout << "_"
                         << " ";
                }
            }
            cout << endl;
        }
        // if we want one possible solution we wil return true and if we want all possible solution we will return false
        return true;
    }

    // Recursive case
    // Try to place the queen in rows and call on the remaining part which wil be solved by recursion
    for (int j = 0; j < n; j++)
    {
        // check if i,j is safe to place the queen or not
        if (isSafe(boards, i, j, n))
        {
            // place the queen - Assuming i,j is the right position
            boards[i][j] = 1;
            bool nextQueenRakhPaye = solveNQueens1(boards, i + 1, n);
            if (nextQueenRakhPaye)
            {
                return true;
            }

            // means i,j is not the right position - assumption is wrong
            boards[i][j] = 0; // backtrack
        }
    }
    // we have tried for all positions in the current row but could not placed the queen
    return false;
}



//count all possible solution
int solveNQueens2(int boards[][10], int i, int n)
{
    // Base case
    if (i == n)
    {
        return 1;
    }

    // Recursive case
    // Try to place the queen in rows and call on the remaining part which wil be solved by recursion
    int count = 0;
    for (int j = 0; j < n; j++)
    {
        // check if i,j is safe to place the queen or not
        if (isSafe(boards, i, j, n))
        {
            // place the queen - Assuming i,j is the right position
            boards[i][j] = 1;
            count += solveNQueens2(boards, i + 1, n);


            // means i,j is not the right position - assumption is wrong
            boards[i][j] = 0; // backtrack
        }
    }
    // we have tried for all positions in the current row but could not placed the queen
    return count;
}
int main()
{
    int n;
    cin >> n;
    int boards[10][10] = {0};
    cout << solveNQueens1(boards, 0, n);
    return 0;
}