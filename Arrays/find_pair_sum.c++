#include<iostream>
using namespace std;

int main()
{
    int a[] = {1,4,5,6,8,10};
    int n = sizeof(a)/sizeof(int);
    int sum;
    cout << "Enter the value of sum : ";
    cin >> sum;
    /*for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(a[i]+a[j] == sum)
            cout << "(" << a[i] << "," << a[j] << ")";
        }
    }
    */
    int i=0, j=n-1;
    while(i<j)
    {
        if(a[i] + a[j] == sum)
        {
            cout << "(" << a[i] << "," << a[j] << ")";
            i++;
            j--;
        }
        if(a[i] + a[j] > sum)
        {
            j--;
        }
        if(a[i] + a[j] < sum)
        {
            i++;
        }
    }
    return 0;
}