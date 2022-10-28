#include <iostream>
#include <string>
using namespace std;

void move(string in, int i, int n)
{
    // base case
    if (i == n)
        return;

    char curr = in[i];
    // recursive case
    if (in[i] != 'x')
        cout << curr;

    move(in, i + 1, n);

    if (in[i] == 'x')
        cout << curr;
}

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    move(s, 0, n);
    return 0;
}