#include<iostream>
#include<cstring>
using namespace std;

void Rotate_string2(char b[], int k)
{
    int len = strlen(b);
    int i = len-1;
    while(i>=0)
    {
        b[i+k] = b[i];
        i--;
    }
    b[len+k]='\0';
    i=0;
    int j=len;
    while(i<k)
    {
        b[i]=b[j];
        i++;
        j++;
    }
    b[len] = '\0';
    cout << b;
}
int main()
{
    char a[100];
    cin.getline(a,100);
    int n; 
    cin >> n;
    Rotate_string2(a,n);
    return 0;
}