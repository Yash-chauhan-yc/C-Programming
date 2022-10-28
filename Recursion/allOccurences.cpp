#include <iostream>
using namespace std;

int output[100];
int j = 0;

int printAllOccurences(int a[], int n, int i, int key)
{
    if (i == n)
        return -1;

    if (a[i] == key)
    {
        cout << i << " ";
        output[j] = i;
        j++;
    }

    return printAllOccurences(a, n, i + 1, key);
}

int main()
{
    int a[] = {1, 2, 3, 2, 4, 2};
    int n = sizeof(a) / sizeof(int);
    printAllOccurences(a, n, 0, 2);
    cout << endl;
    cout << "Indices are : ";
    for (int i = 0; i < j; i++)
    {
        cout << output[i] << " ";
    }
    return 0;
}