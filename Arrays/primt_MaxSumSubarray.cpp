#include<iostream>
using namespace std;

void MaximumSumSubarray(int a[], int n)
{   
    int sum_max = INT_MIN;
    int wi,wj;
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
                wi = i;
                wj = j;
            }
        }
    }
    cout << "Maximum Sum Subarray : ";
    for (size_t i = wi; i <= wj; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
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