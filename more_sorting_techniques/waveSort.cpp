#include<iostream>
using namespace std;

void waveSort(int a[], int n) 
{
    for(int i=0; i<n; i=i+2)
    {
        if(i!=0 && a[i] < a[i-1])
        {
            swap(a[i], a[i-1]);
        }
        if(i!=(n-1) && a[i] < a[i+1])
        {
            swap(a[i],a[i+1]);
        }
    }
    for(int i=0; i<n; i++)
    {
        cout << a[i] << " ";
    }
}


int main()
{
    int a[] = { 1,3,4,2,7,8};
    int n = sizeof(a)/sizeof(int);

    waveSort(a,n);
    return 0;
}