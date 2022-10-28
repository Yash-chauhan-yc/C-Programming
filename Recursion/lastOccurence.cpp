#include <iostream>
using namespace std;

int lastOccurence(int a[], int n, int i, int key)
{
    if (i == 0)
        return -1;

    if (a[i] == key)
        return i;

    return lastOccurence(a, n, i - 1, key);
}

int lastOccurence2(int a[], int n, int i, int key)
{
    if (n == 0)
        return -1;

    if (a[i] == key)
    {
        int bi = lastOccurence2(a, n, i + 1, key);
        if (bi != -1)
            return bi;
        else
            return i;
    }

    int j = lastOccurence2(a, n - 1, i + 1, key);
    return j;
}

int main()
{
    int a[] = {1, 8, 3, 1, 3, 1};
    int n = sizeof(a) / sizeof(int);
    cout << lastOccurence2(a, n, 0, 1);
    return 0;
}