#include <iostream>
using namespace std;

void bubbleSort(int a[], int n, int i)
{

    if (i == n - 1)
        return;

    for (int j = 0; j < n - 1 - i; j++)
    {
        if (a[j] > a[j + 1])
        {
            swap(a[j], a[j + 1]);
        }
    }
    bubbleSort(a, n, i + 1);
}
void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    int a[] = {5, 4, 3, -2, -1, 1, 5};
    int n = sizeof(a) / sizeof(int);
    bubbleSort(a, n, 0);
    print(a, n);
    return 0;
}