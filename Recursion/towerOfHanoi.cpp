#include<iostream>
using namespace std;

void towerOfHanio(int n, char src, char dest, char helper)
{
    // base case
    if(n==0)
    return;

    // recursive case
    // 1. move n-1 disk from source to helper
    towerOfHanio(n-1, src, helper, dest);

    // move nth disk from source to destination
    cout << "move " << n << " disk from " << src << " to " << dest << endl;

    // move n-1 disk from helper to destination
    towerOfHanio(n-1, helper , dest, src);

}

int main()
{
    int n; 
    cin >> n;
    towerOfHanio(n,'A','B','C');
    return 0;
}