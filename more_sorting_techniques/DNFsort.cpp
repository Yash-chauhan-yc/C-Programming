#include <iostream>
#include <algorithm>
using namespace std;

void dnfSort(int a[], int n)
{
    int lo = 0;
    int hi = n - 1;
    int mid = 0;

    while (mid <= hi)
    {
        if (a[mid] == 0)
        {
            swap(a[lo], a[mid]);
            lo++;
            mid++;
        }
        if (a[mid] == 1)
        {
            mid++;
        }
        if (a[mid] == 2)
        {
            swap(a[mid], a[hi]);
            hi--;
        }
    }
    return;
}

int main()
{
    int a[] = {2, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 2, 0};
    int n = sizeof(a) / sizeof(int);
    dnfSort(a,n);
    for(int i=0; i<n;i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}