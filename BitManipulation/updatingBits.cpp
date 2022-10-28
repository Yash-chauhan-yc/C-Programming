#include<iostream>
using namespace std;
void clearBit(int &n, int j, int i)
{
    int ma = (~0);
    ma = ma << j;
    int mb = (1<<i) - 1;
    int mask = ma|mb;
    n = (n&mask);
}
void updatingBits(int &n, int m, int j, int i)
{
    m = (m<<i-1);
    clearBit(n,j,i-1);
    n = n|m;
}
int main()
{
    int n = 15;
    int m = 2;
    updatingBits(n,m,4,2);
    cout << n;
    return 0;
}