#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
void compress(char a[])
{
    char b[100];
    int count=1;
    cout << a[0];
    for(int i=1; i<strlen(a); i++)
    {
        char curr=a[i];
        char prev=a[i-1];
        if(curr == prev)
        count++;
        else
        {
            if(count>1)
            {
                cout << count;
                count = 1; 
            }
            else if(count == 1)
            {
                cout << count;
            }
             cout << curr;
        }
    }
    if(count > 1)
    {
        cout << count;
    }
    else if(count == 1)
    {
        cout << count;
    }
}   
int main()
{
    char a[100];
    cin.getline(a,100);
    compress(a);
    return 0;
}