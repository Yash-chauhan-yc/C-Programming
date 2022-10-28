#include<iostream>
using namespace std;
void count_frequency(char a[])
{
    int freq[26]={0};
    char ch;
    int index;
    for(int i=0; a[i]!='\0'; i++)
    {
        ch = a[i];
        index = ch-'a';
        freq[index]++;
    }
    for(int i=0; i<26; i++)
    {
        if(freq[i] > 0 )
        {
            char x = i + 'a';
            cout << " character " << x << "--> " << freq[i] << endl;
        }
    }
}
int main()
{
    char a[100];
    cin.getline(a,100);
    count_frequency(a);
    return 0;
}