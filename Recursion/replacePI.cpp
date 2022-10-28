#include <iostream>
using namespace std;

void replacePI(char *a, int i)
{
    // base case
    if (a[i] == '\0' || a[i + 1] == '\0')
        return;

    // recursive case
    if (a[i] == 'p' && a[i + 1] == 'i')
    {
        int j = i + 2;
        while (a[j] != '\0')
        {
            j++;
        }
        while (j >= i + 2)
        {
            a[j + 2] = a[j];
            j--;
        }
        a[i] = '3';
        a[i + 1] = '.';
        a[i + 2] = '1';
        a[i + 3] = '4';

        // then ask the recursion to solve the smaller problem from i+4
        replacePI(a, i + 4);
    }
    else
    {
        // then ask the recursion to solve the smaller problem from i+1
        replacePI(a, i + 1);
    }
}

int main()
{
    char a[] = "axpifabpi";
    cout << "Before replacing pi : " << a << endl;
    replacePI(a, 0);
    cout << "after replacing pi : " << a << endl;
    return 0;
}