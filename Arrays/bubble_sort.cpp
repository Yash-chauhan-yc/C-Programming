#include<iostream>
using namespace std;

int main()
{
    int a[100], n;
    cout << "Enter the number of elements : ";
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cout << "Enter the element " << i <<" ";
        cin >> a[i];
    }
    for(int i=0 ; i<=n-2 ; i++)
    {
        for(int j=0 ; j<=n-2 ; j++)
        {
            if(a[j] > a[j+1])
            {
                swap(a[j], a[j+1]);
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}