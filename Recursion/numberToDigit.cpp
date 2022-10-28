#include <iostream>
#include <string>
using namespace std;

void numberToDigit(int n)
{
    string s[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    if(n == 0)
    return;

    numberToDigit(n / 10);
    int digit = n % 10;
    cout << s[digit] << " ";
}
int main()
{
    int n;
    cin >> n;
    numberToDigit(n);
    return 0;
}