#include<iostream>
#include<cstring>
using namespace std;
int count(char a[])
{
	int count = strlen(a); 
	for(int i=0; a[i]!='\0'; i++)
	{
		bool ispalindromic = true;
		for(int j=i+1; a[j]!='\0'; j++)
		{
			int x=i;
			int y=j;
			while(x<y)
			{
				if(a[x]!=a[y])
				{
					ispalindromic =false;
					break;
				}	
				x++;
				y--;
			}
			if(ispalindromic == true)
			count++;
		}
	}
	return count;
}
int main() {
	char c[1000];
	cin.getline(c,1000);
	cout << count(c);
	return 0;
}