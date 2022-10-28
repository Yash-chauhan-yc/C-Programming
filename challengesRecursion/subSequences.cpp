#include <iostream>
#include <string>
using namespace std;
int ans = 0;
void subsequences(char *in, char *out, int i, int j)
{
   
    if (in[i] == '\0')
    {
        out[j] = '\0';
        cout << out << " ";
        ans++;
        return;
    }

    // Recursive case
    //  1. ignore the ith character
    subsequences(in, out, i + 1, j);

    out[j] = in[i];

    // consider the ith character
    subsequences(in, out, i + 1, j + 1);
}

int main()
{
    char a[100];
    cin >> a;
    char b[100];
    subsequences(a, b, 0, 0);
    cout << endl;
    cout << ans;
    return 0;
}