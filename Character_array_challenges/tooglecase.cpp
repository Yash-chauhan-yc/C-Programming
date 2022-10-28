#include<iostream>
#include<cstring>
using namespace std;
void toggleCase(char a[])
{
    int x;
    for(int i=0; a[i]!='\0'; i++)
    {
        if(a[i] >= 'a' && a[i] <= 'z')
        {
            x = (int)(a[i]);
            x -= 32;
            a[i] = char(x);
        }
        else if(a[i] >= 'A' && a[i] <= 'Z')
        {
            x = (int)(a[i]);
            x += 32;
            a[i] = char(x);
        }
    }
    for(int i=0;  a[i]!='\0'; i++)
    {
        cout << a[i];
    }
}
int main()
{
    char a[100];
    cin.getline(a,100);
    toggleCase(a);
    return 0;
}