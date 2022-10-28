#include <iostream>
using namespace std;

int partition(int *a, int s, int e)
{
    int i = s - 1;
    for (int j = s; j <= e - 1; j++)
    {
        if (a[j] <= a[e])
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[e]);
    return i + 1;
}

void quickSort(int *a, int s, int e)
{
    if (s >= e)
        return;

    int pivot = partition(a, s, e);
    quickSort(a, s, pivot - 1);
    quickSort(a, pivot + 1, e);
}

int main()
{
    int a[] = {5, 4, 3, 2, 1, 8};
    int n = sizeof(a) / sizeof(int);
    cout << "before sorting : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    quickSort(a, 0, n - 1);
    cout << "after sorting : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}