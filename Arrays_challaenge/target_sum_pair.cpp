#include<iostream>
#include<algorithm>
using namespace std;

void TargetSum(int a[], int n, int target)
{
    sort(a, a+n);
    int i=0;
    int j=n-1;
    while(i<j)
    {
        if(a[i] + a[j] == target)
        {
            cout << a[i] << " and " << a[j] << endl;
            i++;
            j--;
        }
        if(a[i] + a[j] > target)
        {
            j--;
        }
        if(a[i] + a[j] < target)
        {
            i++;
        }
    }
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
    int x;
    cin >> x;
    TargetSum(a,n,x);
    return 0;
}
//5134255