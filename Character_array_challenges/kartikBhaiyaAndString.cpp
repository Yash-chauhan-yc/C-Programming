#include<iostream>
#include<cstring>
using namespace std;
void print(char a[], int k)
{

    for(int i=0; i<strlen(a); i++)
    {
        for(int j=0; j<=k; j++)
        {
            
        }
    }
    for(int i=0; i<strlen(a); i++)
    {
        cout << a[i];
    }
}
int main()
{
    char a[100];
    cin.getline(a,100);
    print(a,3);
    return 0;
}