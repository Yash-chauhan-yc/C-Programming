#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[10000];
    
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    int k; 
    cin >> k;

    int max;

    for(int i=0; i<n-k; i++)
    {
        max = a[i];
        for(int j=1; j<k; j++)
        {
            if(a[i+j] > max)
            {
                max = a[i+j];
            }
        }
        cout << max;
    }
    return 0;
}