#include<iostream>
#include<cstring>
using namespace std;
void palindromic(char c[])
{
    bool ispalindrome = true;
    int j = strlen(c) - 1;
    int i=0;
    while(i<j){
        if(c[i] != c[j])
        {
            ispalindrome = false;
            cout << "not a palindrome";
            break;
        }
        i++;
        j--;
    }
    if(ispalindrome == true)
    {
        cout << "string is palindrome ";
    }
}

void check_palindrome(char a[])
{
    char b[100];
    int i=0;
    bool ispalindrome=true;
    for(int j=strlen(a)-1; j>=0; j--)
    {
        b[j] = a[i];
        i++;
    }
    for(int i=0; a[i]!='\0' && b[i]!='\0'; i++)
    {
        if(a[i] != b[i])
        {
            ispalindrome = false;
            cout << " not a palindrome ";
            break;
        }
    }
    if(ispalindrome == true)
    {
        cout << "palindrome";
    }
}
int main()
{
    char a[100];
    cin.getline(a,100);
    palindromic(a);
    cout << endl;
    check_palindrome(a);
}