#include <iostream>
using namespace std;

int firstOccurence(int a[], int n, int key)
{
    if (n == 0)
        return -1;

    if (a[0] == key)
        return 0;

    int i = firstOccurence(a + 1, n - 1, key);
    if (i == -1)
    {
        return -1;
    }
    return i + 1;
}

int firstOccurenceIter(int a[], int n, int i, int key)
{
    if (i == n)
        return 0;

    if (a[i] == key)
        return i;

    return firstOccurenceIter(a, n, i + 1, key);
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(a) / sizeof(int);

    cout << firstOccurenceIter(a, n, 0, 7);

    return 0;
}