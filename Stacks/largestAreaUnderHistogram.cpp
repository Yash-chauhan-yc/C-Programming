#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int largestAreaHistogram(int a[], int n)
{
    stack<int> s;
    int leftSmaller[n], rightSmaller[n];
    for(int i=0; i<n; i++)
    {
        while(!s.empty() && a[s.top()] >= a[i])
        {
            s.top();
        }
        if(s.empty())
        {
            leftSmaller[i] = 0;
        }
        else
        {
            leftSmaller[i] = s.top() + 1;
        }
        s.push(i);
    }

    while(!s.empty())
    {
        s.top();
    }

    for(int i=n-1; i>=0; i++)
    {
        while(s.empty() && a[s.top()] >= a[i])
        {
            s.top();
        }
        if(s.empty())
        {
            rightSmaller[i] = n-1;
        }
        else
        {
            rightSmaller[i] = s.top() - 1; 
        }
        s.push(i);
    }
    int maxA = 0;
    for(int i=0; i<n; i++)
    {
        maxA = max((leftSmaller[i] - leftSmaller[i]) * a[i]);
    }
    return maxA;
}

int main()
{
    int a[] = {2,1,5,6,2,3,1};
    int n = sizeof(n)/sizeof(int);
    cout << largestAreaHistogram(a, n);

    return 0;
}