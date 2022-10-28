#include <iostream>
using namespace std;

int lastElement(int a[], int n, int i, int key)
{
    if (i == 0)
        return -1;

    if (a[i] == key)
    {
        return i;
    }
    else
    {
        return lastElement(a, n, i - 1, key);
    }
}

int main()
{
    int a[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int key;
    cin >> key;
    cout << lastElement(a, n, n, key);
    return 0;
}