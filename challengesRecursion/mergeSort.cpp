#include <iostream>
using namespace std;

void merge(int *a, int *b, int *c, int s, int e)
{
    int mid = (s + e) / 2;
    int i = s;
    int j = mid + 1;
    int k = s;
    while (i <= mid && j <= e)
    {
        if (b[i] <= c[j])
        {
            a[k++] = b[i++];
        }
        else
        {
            a[k++] = c[j++];
        }
    }
    while (i <= mid)
    {
        a[k++] = b[i++];
    }
    while (j <= e)
    {
        a[k++] = c[j++];
    }

}

void mergeSort(int *a, int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }
    int b[100];
    int c[100];
    int mid = (s + e) / 2;
    for (int i = s; i <= mid; i++)
    {
        b[i] = a[i];
    }
    for (int i = mid + 1; i <= e; i++)
    {
        c[i] = a[i];
    }

    // recursive case
    mergeSort(b, s, mid);
    mergeSort(c, mid + 1, e);
    merge(a, b, c, s, e);
}

int main()
{
    int a[1000];
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    mergeSort(a, 0, n-1);
    for(int i=0; i<n; i++)
    {
        cout << a[i];
    }
    return 0;
}