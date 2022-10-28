#include<iostream>
#include<cstring>
using namespace std;

int stringToInt(char s[], int n)
{
    if(n==0)
    return 0;

    int digit = s[n-1] - '0';
    int smallerAnswer = stringToInt(s, n-1);
    int biggerAnswer = smallerAnswer * 10 + digit;
    return biggerAnswer;

}

int main()
{
    char a[] = "4329";
    int n = strlen(a);
    int ans = stringToInt(a, n);
    cout << ans << endl;
    cout << ans + 1 << endl;
    return 0;
}