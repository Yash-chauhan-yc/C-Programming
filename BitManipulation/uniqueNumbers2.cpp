#include <iostream>
using namespace std;

int main()
{
    int a[] = {6, 5, 1, 6, 1, 3};
    int n = sizeof(a) / sizeof(int);
    int ans;
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ a[i];
    }
    int result = ans;

    int pos = 0;
    while (ans > 0)
    {
        if ((ans & 1) > 0)
        {
            break;
        }
        pos++;
        ans = ans >> 1;
    }
    int x = 1 << pos;
    int un1 = 0;
    for (int i = 0; i < n; i++)
    {
        if ((a[i] & x) == 0)
            un1 ^= a[i];
    }
    cout << un1 << " ";

    int un2 = result ^ un1;
    cout << un2;
    return 0;
}