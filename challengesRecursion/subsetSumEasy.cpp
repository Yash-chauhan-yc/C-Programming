#include <iostream>
using namespace std;

bool subset(int a[], int i, int n, int sum, int count)
{
    // base case
    if (i == n)
    {
        if (sum == n && count > 0)
            return true;
        else
            return false;
    }
    // recursion case
    bool opt1 = subset(a, i + 1, n, sum + a[i], count + 1);

    bool opt2 = subset(a, i + 1, n, sum, count);
    return opt1 + opt2;
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        int input[100];
        for (int i = 0; i < n; i++)
        {
            cin >> input[i];
        }
        if (subset(input, 0, n, 0, 0))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}