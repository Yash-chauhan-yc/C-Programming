#include <iostream>
using namespace std;

bool isSafe(int a[][10], int n, int i, int j)
{
     // check for column
    for (int row = 0; row < i; row++)
    {
        if (a[row][j] == 1)
            return false;
    }

    // check for left diagonal
    int x = i;
    int y = j;
    while (x >= 0 && y >= 0)
    {
        if (a[x][y] == 1)
            return false;
        x--;
        y--;
    }

    // check for right diagonal
    x = i;
    y = j;
    while (x >= 0 && y < n)
    {
        if (a[x][y] == 1)
            return false;
        x--;
        y++;
    }

    // now the postion is safe from columns and diagonals
    return true;
}

int NQueens(int a[][10], int n, int i)
{
    // base case
    if (i == n)
    {
        return 1;
    }
    int count = 0;
    for (int j = 0; j < n; j++)
    {
        if (isSafe(a, n, i, j))
        {
            a[i][j] = 1;
            count+=NQueens(a, n, i + 1);
        
            // backtrack
            a[i][j] = 0;
        }
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    int boards[10][10] = {0};
    cout << NQueens(boards, n, 0);
    return 0;
}