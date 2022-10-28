#include<iostream>
using namespace std;
int countSetBits(int n)
{
    int count=0;
    while(n>0)
    {
        int ans = (n&1);
        if(ans == 1)
        {
            count++;
        }
        n = n>>1;
    }
    return count;
}
int main()
{
    int n=5;
    cout << countSetBits(n);
    return 0;
}