#include<iostream>
using namespace std;

void mappedString(char *in, char *out, int i, int j)
{
    // base case
    if(in[i] == '\0')
    {
        out[j] = in[i];
        cout << out << endl;
        return;
    }

    // recursive case
    int digit = in[i] - '0';
    char ch = digit + 'A' - 1;
    out[j] = ch;

    mappedString(in, out, i+1, j+1);
    if(in[i+1] != '\0')
    {
        int secondDigit = in[i+1] - '0';
        int no = digit * 10 + secondDigit;
        if(no <= 26)
        {
            ch = no + 'A' - 1;
            out[j] = ch;
            mappedString(in, out, i+2, j+1);
        }
    }
}

int main()
{
    char a[100];
    cin >> a;
    char b[100];
    mappedString(a, b, 0, 0);
    return 0;
}