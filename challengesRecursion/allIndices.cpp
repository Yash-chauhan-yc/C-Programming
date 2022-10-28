#include<iostream>
using namespace std;

void allIndices(int a[], int n, int i, int key)
{
    // base case
    if(i==n)
    {
        return;
    }

    // recursive case
    if(a[i] == key)
    {
        cout << i << " ";
    }
    return allIndices(a,n,i+1,key);
}

int main()
{
    int n;
    cin >> n;
    int a[1000];
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    int key;
    cin >> key;
    allIndices(a,n,0,key);

    return 0;
}