#include<iostream>
#include<cstring>
using namespace std;
void read(char a[])
{
    char b[100];
    for(int i=0; i<strlen(a); i++)
    {
        if(a[i]>='A' && a[i]<='Z')
        cout << endl;
        cout << a[i];
    }
}
int main()
{
    char a[100];
    cin.getline(a,100);
    read(a);
    return 0;
}