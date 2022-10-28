#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
void diff(char a[])
{
    int b[100];
    cout << a[0];
    int i=1;
    while(a[i] != '\0')
    {
        b[i] = (int)(a[i]) - (int)(a[i-1]);
        cout << b[i] << a[i];
        i++;
    }
}
int main()
{
    char a[100];
    cin.getline(a,100);
    diff(a);
    return 0;
}