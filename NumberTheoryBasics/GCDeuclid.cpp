#include <iostream>
using namespace std;

int GCD(int a, int b)
{
    int ans = 0;
    for (int i = 1; i <= a && i <=b ; i++)
    {
        if ((a % i) == 0 && (b % i) == 0)
        {
            ans = i;
        }
    }
    return ans;
}

int GCDeuclidAlgo(int a, int b)
{
    return b==0 ? a : GCDeuclidAlgo(b,a%b);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << GCDeuclidAlgo(a, b);
    return 0;
}