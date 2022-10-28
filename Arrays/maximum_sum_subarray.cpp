#include<iostream>
using namespace std;

void MaximumSumSubarray(int a[], int n)
{   
    int sum_max = INT_MIN;
    for(int i=0; i<n; i++)
    {   
        for(int j=i; j<n; j++)
        {
            int sum = 0;
            for(int k=i; k<=j; k++)
            {
                sum += a[k];
            }
            if(sum_max < sum)
            {
                sum_max = sum;
            }
        }
    }
    cout << "maximum sum : " << sum_max;
}

int main()
{
    int a[] = {1,2,3,4};
    int sum = 0;
    int n = sizeof(a)/sizeof(int);
    MaximumSumSubarray(a,n);
 
    return 0;
}