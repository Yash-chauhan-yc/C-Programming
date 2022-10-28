#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[100];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ a[i];
    }
    int result = ans;
    int pos = 0;
    while (ans > 0)
    {
        if ((ans & 1) == 1)
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
        if ((a[i] & x) > 0)
            un1 ^= a[i];
    }
    cout << un1;
    /*int un2 = 0;
    un2 = result^un1;
    cout << un2;*/
    return 0;
}