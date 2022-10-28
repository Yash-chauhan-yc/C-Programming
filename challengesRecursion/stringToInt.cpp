#include <iostream>
#include <string>
using namespace std;

int stringToInt(string s, int n)
{
    // base case
    if (n == 0)
        return 0;
    // recursive case
    int digit = s[n - 1] - '0';
    int smallerAnswer = stringToInt(s, n - 1);
    int biggerAnswer = smallerAnswer * 10 + digit;
    return biggerAnswer;
}

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    cout << stringToInt(s, n);

    return 0;
}