#include<iostream>
using namespace std;

void MaximumSumSubarray(int a[], int n)
{   
    int sum_max = INT_MIN;
    int csum[100] = {0};
    int wi, wj;
    for(int i=0; i<n; i++)
    {
        csum[i] = csum[i-1] + a[i];
    }
    for(int i=0; i<n; i++)
    {   
        for(int j=i; j<n; j++)
        {
            int sum = 0;
            sum = csum[j] - csum[i-1];
            if(sum_max < sum)
            {
                sum_max = sum;
                wi=i;
                wj=j;
            }
        }
    }
    cout << "Maximum Sum Subarray : ";
    for (size_t i = wi; i <= wj; i++)
    {
        cout << a[i] << " ";
    }
    cout << "maximum sum : " << sum_max;
}

int main()
{
    int a[] = {0,-1,2,-2,3,6,-4,-3};
    int sum = 0;
    int n = sizeof(a)/sizeof(int);
    MaximumSumSubarray(a,n);
 
    return 0;
}