#include<iostream>
using namespace std;
int cnt=0;
void cal(int *a,int i,int j,int sum)
{
	if(i==j)
	{
		cout<<sum;
		return;
	}
	
	if(cnt==0)
	{
		if(a[i]>a[j])
		{
			sum+=a[i];
			i=i+1;
		}
		else
		{
			sum+=a[j];
			j=j-1;
		}
		cnt++;
		cal(a,i,j,sum);
	}
	else{
		if(a[i]>a[j])
		{
			i=i+1;
		}
		else
		{
			j=j-1;
		}
		cnt--;
		cal(a,i,j,sum);
	}
	return;
}
int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	cal(a,0,n-1,0);
	return 0;
}