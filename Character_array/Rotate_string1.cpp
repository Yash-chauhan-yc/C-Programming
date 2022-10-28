#include<iostream>
#include<cstring>
using namespace std;
void Rotate_string1(char a[], int n)
{
    int len = strlen(a);
    char ch;
    for(int i=0; i<n; i++)
    {
       int j=len-1;
       ch = a[len-1];
       while(j>=0)
        {
            a[j] = a[j-1];
            j--;
        }
        a[0] = ch;

    }
    cout << a << endl;
}
int main()
{
    char a[100];
    cin.getline(a,100);
    int n; 
    cin >> n;
    Rotate_string1(a,n);
    return 0;
}