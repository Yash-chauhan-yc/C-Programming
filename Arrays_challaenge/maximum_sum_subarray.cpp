#include<iostream>
using namespace std;
 
void max_subarray(int a[], int n)
{
    int max_sum = 0;

        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
            {
                int sum = 0;       
                for(int k=i; k<=j; k++)
                {
                    sum += a[k];
                }
                if(max_sum < sum)
                {
                    max_sum = sum;
                }
            }
        }
    
    cout << max_sum;
}


int main()
{
    int x; 
    cin >> x;
    for(int j=0; j<x; j++)
    {
        int n; 
        cin >> n;
        int a[n];
        for(int i=0; i<n; i++)
        {
            cin >> a[i];
        }
        max_subarray(a,n);
        cout << endl;
    }   
    
    return 0;
}