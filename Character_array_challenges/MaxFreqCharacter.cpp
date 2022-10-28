#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
void maxFreq(char a[])
{
	int freq[26] = {0};
	for(int i=0; a[i]!='\0'; i++)
	{
		freq[a[i] - 'a']++;
	}
    for(int i=0; i<26; i++)
    {
        cout << freq[i] << " ";
    }
    cout << endl;
    int max =0;
    char x;
	for(int i=0; i<26; i++)
	{
		if(max < freq[i])
        {
            max = freq[i];
            x = (char)(i + 'a');
        }
	}
    cout << x;
	
}
int main() {
	char a[100];
	cin.getline(a,100);
	maxFreq(a);
	return 0;
}