#include <iostream>
using namespace std;

int binarySearch(int a[], int s, int e, int key)
{
    if (s > e)
        return -1;

    int mid = (s + e) / 2;
    if (a[mid] == key)
        return mid;
    else if (a[mid] < key)
        return binarySearch(a, mid + 1, e, key);
    else
        return binarySearch(a, s, mid - 1, key);
}
int main()
{
    
    int a[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(a) / sizeof(int);
    cout << binarySearch(a, 0, n-1, 4);
}