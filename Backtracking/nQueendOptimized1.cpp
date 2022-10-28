#include <iostream>
#include <bitset>
using namespace std;

bitset<30> col, d1, d2;

void solve(int r, int n, int &ans, int board[][10])
{
    if (r == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 1)
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
        ans++;
        return;
    }
    for (int c = 0; c < n; c++)
    {
        if (!col[c] && !d1[r - c + n - 1] && !d2[r + c])
        {
            // placing the queen
            col[c] = d1[r - c + n - 1] = d2[r + c] = board[r][c] = 1;
            solve(r + 1, n, ans, board);
            // Backtracking
            col[c] = d1[r - c + n - 1] = d2[r + c] = board[r][c] = 0;
        }
    }
}
int main()
{
    int board[][10] = {0};
    int n;
    cin >> n;
    int ans = 0;
    solve(0, n, ans, board);
    cout << ans << endl;
    return 0;
}