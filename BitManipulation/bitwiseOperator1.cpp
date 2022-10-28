#include<iostream>
using namespace std;

void clearBit(int &n, int i)
{
    int mask = 1<<i;
    mask = (~mask);
    n = (n&mask);
}

void updateBit(int &n, int i, int v)
{
    
    int mask = 1<<i;
    mask = (~mask);
    n = (n&mask);
    v = v<<i;
    n = v|n;
}

void evenOdd(int &n)
{
    int ans = (n&1);
    if(ans == 0)
    cout << "even";
    else
    cout << "odd";
}

void checkith(int &n, int i)
{
    int mask = (1<<i);
    if((n&mask) == 0)
    cout << "0";
    else
    cout << "1";
}

void setithBit(int &n, int i)
{
    int mask = (1<<i);
    n = (n|mask);
    cout << n;
}

int main()
{
   int n = 5 ;
   setithBit(n,3);
    return 0;
}