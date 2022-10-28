#include <iostream>
#include <string>
using namespace std;

void duplicateRecursion(string in, int i)
{
    if (i == in.length())
    {
        return;
    }
    if (in[i] == in[i + 1])
    {
        cout << in[i] << "*";
        return duplicateRecursion(in, i+1);
    }
    else
    {
        cout << in[i];
        return duplicateRecursion(in,i+1);
    }
}

int main()
{
    string in;
    cin >> in;
    duplicateRecursion(in, 0);
    return 0;
}