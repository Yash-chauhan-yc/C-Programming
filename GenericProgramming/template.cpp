#include <iostream>
using namespace std;
template <class T>
int LinearSearch(T arr[], int n, T key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return n;
}
int main()
{
    int a[] = {1, 3, 4, 5, 7, 12};
    int n = sizeof(a) / sizeof(int);
    cout << LinearSearch(a, n, 12);
    return 0;
}