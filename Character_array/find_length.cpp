#include<iostream>
using namespace std;

int main()
{
    char a[100];
    int count;
    cin.getline(a,100);
    for(int i=0; a[i]!='\0'; i++)
    {
        count++;
    }
    cout << count;
    return 0;
}