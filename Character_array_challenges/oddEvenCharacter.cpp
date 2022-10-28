#include<iostream>
using namespace std;
void oddEvenCharacter(char a[])
{
    int x;
    for(int i=0; a[i]!='\0'; i++)
    {
        if(i%2==0)
        {
            x = (int)(a[i]);
            x++;
            a[i] = char(x);
        }
        if(i%2!=0)
        {
            x = (int)(a[i]);
            x--;
            a[i] = char(x);
        }
    }
    for(int i=0; a[i]!='\0'; i++)
    {
        cout << a[i];
    }
}
int main()
{
    char c[100];
    cin.getline(c,100);
    oddEvenCharacter(c);
    return 0;
} 