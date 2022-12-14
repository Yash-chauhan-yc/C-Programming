#include <iostream>
using namespace std;

int partition(int a[], int s, int e)
{
    int i = s - 1;
    for (int j = s; j <= e - 1; j++)
    {
        if (a[j] < a[e])
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[e]);
    return i + 1;
}

void QuickSort(int a[], int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }

    // recursive case
    int pivot = partition(a, s, e);
    QuickSort(a, s, pivot - 1);
    QuickSort(a, pivot + 1, e);
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
    QuickSort(a, 0, n-1);
    for(int i=0; i<n; i++)
    {
        cout << a[i];
    }
    return 0;
}