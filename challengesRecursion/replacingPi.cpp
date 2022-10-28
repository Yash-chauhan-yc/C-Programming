#include<iostream>
using namespace std;

void ReplacingPi(char *a, int i)
{
    // base case
    if(a[i] == '\0' || a[i+1] == '\0')
    {
        return;
    }

    
    // recursive case
    if(a[i] == 'p' && a[i+1] == 'i')
    {
        int j = i+2;
        while(a[j]!='\0')
        {
            j++;
        }
        while(j>=i+2)
        {
            a[j+2] = a[j];
            j--;
        }
        a[i] = '3';
        a[i+1] = '.';
        a[i+2] = '1';
        a[i+3] = '4';

        ReplacingPi(a, i+4);
    }
    else
    {
        ReplacingPi(a, i+1);
    }
}

int main()
{
    char a[100];
    cin >> a;
    ReplacingPi(a,0);
    cout << a;
    return 0;
}