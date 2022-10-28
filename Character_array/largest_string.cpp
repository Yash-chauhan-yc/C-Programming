#include<iostream>
#include<cstring>
using namespace std;
void largest_string(char a[])
{
    int n;
    cin >> n;
    char largest[100];
    int largest_len =0;
    cin.get();
    for(int i=0; i<n; i++)
    {
        cin.getline(a,100);
        int len=strlen(a);
        if(largest_len < len)
        {
            largest_len = len;
            strcpy(largest,a);
        }
    }
    cout << largest << endl;
    cout << "largest : "<< largest_len;
}
int main()
{
    char a[100];
    largest_string(a);
    return 0;
}