#include<iostream>
using namespace std;

void rainwater(int a[], int n)
{
    int res = 0;
    for(int i=1; i<n; i++)
    {
        int left = a[i];
        for(int j=0; j<i; j++)
        {
            left = max(left, a[j]);
        }

        int right = a[i]; 
        for (int j=i+1; j<n; j++) 
        {
            right = max(right, a[j]);
        }
    res = res + min(left, right) - a[i];
    }
    cout << res;
   
}
int main()
{
    int n; 
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    rainwater(a,n);
    return 0;
}