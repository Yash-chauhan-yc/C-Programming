#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

bool mycompare(string a,string b){
    int i=0;
    while(a[i]==b[i]) i++;
    if(a[i]=='\0') return false;
    else if(b[i]=='\0') return true;
    return a < b;
}
void stringSort(string s[], int n)
{
    sort(s,s+n,mycompare);

    for(int i=0; i<n; i++)
    {
        cout << s[i] << " ";
    }
}
int main()
{
    int n; 
    cin >> n;
    string s[10000];
    cin.get();
    for(int i=0; i<n; i++)
    {
        getline(cin, s[i]);
    }
    stringSort(s,n);
    return 0;
}