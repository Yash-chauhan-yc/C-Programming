#include <iostream>
using namespace std;

void printDec(int n)
{
    if (n == 0)
        return;

    cout << n << " ";
    printDec(n - 1) ;
}

void printInc(int n)
{
    if (n == 0)
        return;
    
    printInc(n - 1) ;
    cout << n << " ";
}

void printInc2(int n, int i)
{
    if(i == n+1)
    {
        return;
    }

    cout << i;
    printInc2(n,i+1);
}

int main()
{
    int n;
    cin >> n;
    printInc(n);
    return 0;
}