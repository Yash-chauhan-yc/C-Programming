#include <iostream>
using namespace std;

void balancedParanthesis(char *in, int n, int i, int open, int close)
{

    // base case
    if (i == 2 * n)
    {
        in[i] = '\0';
        cout << in << endl;;
        return;
    }

    // recursive case
    if (open < n)
    {
        in[i] = '(';
        balancedParanthesis(in, n, i + 1, open + 1, close);
    }
    if (open > close)
    {
        in[i] = ')';
        balancedParanthesis(in, n, i + 1, open, close + 1);
    }
}

int main()
{
    int n;
    cin >> n;
    char a[100];
    balancedParanthesis(a, n, 0, 0, 0);
    return 0;
}