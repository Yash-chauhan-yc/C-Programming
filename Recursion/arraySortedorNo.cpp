#include<iostream>
using namespace std;

bool isSorted(int a[], int n)
{
    // base case
    if(n==0 || n==1)
    {
        return true;
    }
    
    // recursive case
    bool isSmallerSorted = isSorted(a+1,n-1);
    if(isSmallerSorted && a[0]<a[1])
    return true;
    else
    return false;
}

bool isSortedUsingIterator(int a[], int n, int i)
{
    if(i==n-1)
    return true;

    bool smallerArray = isSortedUsingIterator(a,n,i+1);
    if(smallerArray && a[i]<a[i+1])
    return true;
    else
    return false;

}

int main()
{
    int a[] = {20,4,6,8,9,10};
    int n = sizeof(a)/sizeof(int);

    bool ans = isSortedUsingIterator(a,n,0);
    if(ans == true)
    cout << "sorted";
    else
    cout << " unsorted ";
    return 0;
}