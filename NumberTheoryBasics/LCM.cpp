#include <iostream>
using namespace std;
int LCM(int a, int b)
{
    int res;
    for (int i = a; i <= a * b; i++)
    {
        if ((i % a) == 0 && (i % b) == 0)
        {
            res = i;
            break;
        }
    }
    return res;
}

int GCD(int a, int b)
{
    return b == 0 ? a : GCD(b, a % b);
}


int main()
{
    int a, b;
    cin >> a >> b;
    cout << a*b/GCD(a,b);
    return 0;
}