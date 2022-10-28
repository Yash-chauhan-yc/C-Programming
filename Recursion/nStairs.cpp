#include <iostream>
using namespace std;

int nStairs(int n)
{
    if (n == 0)
        return 1;

    if (n < 0)
        return 0;

    return nStairs(n - 1) + nStairs(n - 2) + nStairs(n - 3);
}

int Nstairs(int n, int k)
{
    if (n == 0)
        return 1;

    if (n < 0)
        return 0;

    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ans += Nstairs(n - i, k);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << nStairs(n) << endl;
    cout << Nstairs(n, 3);
    return 0;
}