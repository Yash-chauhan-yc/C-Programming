#include<iostream>
#include<algorithm>
using namespace std;
void K_unique_substring(char c[], int k)
{
    int freq[26]={0};
    int cnt =0; 
    int i=0;
    int len=-1;
    for(int j=0; c[j]!='\0'; j++)
    {
        freq[c[j]-'a']++;
        if(freq[c[j]-'a'] == 1)
            cnt++;
    
        while(cnt > k)
        {
            freq[c[i]-'a']--;
            if(freq[c[i]-'a'] == 0)
                cnt--;
            i++; 
        }
        if(cnt == k)
        {
            len = max(len, j-i+1);
        }
    }
    cout << "largest string length with " << k << " unique characters is " <<  len;
}
int main()
{
    char a[100];
    cin.getline(a,100);
    int k;
    cin >> k;
    K_unique_substring(a,k);
    return 0;
}