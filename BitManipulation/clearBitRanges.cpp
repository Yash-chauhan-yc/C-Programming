#include<iostream>
#include<algorithm>
using namespace std;
void clearBitRanges(int n, int i)
{
    int mask = (~0);
    mask = (mask << i);
    n = (n&mask);
    cout << n;
}

void clearBitRangesiToj(int n, int j, int i)
{
    int ma = (~0);
    ma = ma << j;
    // int mb = 2^i - 1;
    int mb = (1<<i) - 1;
    int mask = (ma|mb);
    n = (n&mask);
    cout << n;
}
int main()
{
    int n = 15;
    clearBitRangesiToj(n,3,1);
    return 0;
}