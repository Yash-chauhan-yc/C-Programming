#include <iostream>
using namespace std;

int main()
{
    int a[] = {3, 3, 5, 6, 6, 6, 3};
    int n = sizeof(a) / sizeof(int);
    int count[64] = {0};
    for (int i = 0; i < n; i++)
    {
        int pos = 0;
        int no = a[i];
        while (no > 0)
        {
            if ((no & 1) == 1)
                count[pos]++;
        }
        pos++;
        no = no >> 1;
    }

    for (int i = 0; i < 64; i++)
    {
        count[i] %= 3;
    }
    int ans = 0;
    int p = 1;
    for (int i = 0; i < 64; i++)
    {
        ans += count[i] * p;
        p = p * 2;
    }
    cout << ans;
    return 0;
}