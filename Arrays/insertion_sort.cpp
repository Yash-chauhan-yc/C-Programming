#include<iostream>
using namespace std;

int main()
{
    int a[100], n, i, j;
    cout << "Enter the no of elements in array : ";
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cout << "Enter the " << i << " element : ";
        cin >> a[i];
    }
    for(i=1; i<n; i++)
    {
        int puc = a[i];
        for(j=i-1; j>=0 && a[j]>puc; j--)
        {
            a[j+1] = a[j];
        }
        a[j+1] = puc;
    }
    for(int i=0; i<n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}