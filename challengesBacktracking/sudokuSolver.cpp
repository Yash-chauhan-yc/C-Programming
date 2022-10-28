#include <iostream>
#include <cmath>
using namespace std;

bool isSafe(int a[1000][1000], int n, int i, int j, int number)
{
    // row and column check
    for (int x = 0; x < n; x++)
    {
        if (a[x][j] == number || a[i][x] == number)
        {
            return false;
        }
    }
    int sn = sqrt(n);
    int sx = (i / sn) * sn;
    int sy = (j / sn) * sn;
    for (int k = sx; k < sx + sn; k++)
    {
        for (int l = sy; l < sy + sn; l++)
        {
            if (a[k][l] == number)
            {
                return false;
            }
        }
    }
    return true;
}

bool sudokuSolver(int a[1000][1000], int n, int i, int j)
{
    // base case
    if (i == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    }

    // recursive case
    if (j == n)
    {
        return sudokuSolver(a, n, i + 1, 0);
    }
    if (a[i][j] != 0)
    {
        return sudokuSolver(a, n, i, j + 1);
    }

    for (int number = 1; number <= n; number++)
    {
        if (isSafe(a, n, i, j, number))
        {
            a[i][j] = number;
            bool canWeSolve = sudokuSolver(a, n, i, j+1);
            if (canWeSolve == true)
            {
                return true;
            }
        }
    }

    // backtrack
    a[i][j] = 0;
    return false;
}

int main()
{
    int n;
    cin >> n;
    int a[1000][1000];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> a[i][j];
        }
    }
    sudokuSolver(a, 9, 0, 0);
    return 0;
}