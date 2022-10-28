#include <iostream>
using namespace std;
int exponentiation(int a, int b)
{
    int ans = 1;
    while (b > 0)
    {
        if ((b & 1) == 1)
        {
            ans = ans * a;
        }
        a = a * a;
        b = b >> 1;
    }
    return ans;
}
int main()
{
    cout << exponentiation(3, 4);
    return 0;
}