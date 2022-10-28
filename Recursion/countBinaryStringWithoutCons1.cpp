#include <iostream>
using namespace std;

int countBinaryStrings(int n, int ld)
{
    //base case
    if (n == 0)
        return 0;

    if (n == 1)
    {
        if (ld == 0)
            return 2;
        else
            return 1;
    }

    // recursive case
    if (ld == 0)
        return countBinaryStrings(n - 1, 0) + countBinaryStrings(n - 1, 1);
    else
        return countBinaryStrings(n - 1, 0);
}

int main()
{
    int n;
    cin >> n;
    cout << countBinaryStrings(n, 0);
    return 0;
}