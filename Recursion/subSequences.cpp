#include <iostream>
using namespace std;

void subSequences(char *in, char *out, int i, int j)
{
    // base case
    if (in[i] == '\0')
    {
        out[j] = '\0';
        cout << out << endl;
        return;
    }

    // Recursive case
    // 1. ignore the ith character
    subSequences(in, out, i + 1, j);

    // 2. Take the ith character in output array
    out[j] = in[i];
    subSequences(in, out, i + 1, j + 1);
}

int main()
{
    char in[] = "abc";
    char out[100];

    subSequences(in, out, 0, 0);
    return 0;
}