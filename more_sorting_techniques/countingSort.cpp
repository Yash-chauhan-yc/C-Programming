#include <iostream>
#include <algorithm>
using namespace std;

void countSort(int *a, int n)
{
    int largest = -1;
    for (int i = 0; i < n; i++)
    {
        largest = max(a[i], largest);
    }
    int *freq = new int[largest + 1]{0};

    for (int i = 0; i < n; i++)
    {
        int index = a[i];
        freq[index]++;
    }

    // put the element back into the array a by reading freq array
    int j = 0;
    for (int i = 0; i <= largest; i++)
    {
        while (freq[i] > 0)
        {
            a[j] = i;
            freq[i]--;
            j++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    int a[] = {88, 97, 10, 12, 15, 1, 5, 6, 12, 5, 8};
    int n = sizeof(a) / sizeof(int);
    countSort(a, n);
    return 0;
}