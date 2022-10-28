#include<iostream>
#include<algorithm>
using namespace std;
void linearSort(int a[], int n)
{
	int low=0;
	int mid=0;
	int high=n-1;
	while(mid<=high)
	{
		if(a[mid] == 0)
		{
			swap(a[low],a[mid]);
			low++;
			mid++;
		}
		else if(a[mid]==1)
		{
			mid++;
		}
		else
		{
			swap(a[mid],a[high]);
			high--;
		}
	}
}
int main() {
	int n;
	cin >> n;
	int a[100000];
	for(int i=0; i<n; i++)
	{
		cin >> a[i];
	}
	linearSort(a,n);
    for(int i=0; i<n; i++)
	{
		cout << a[i];
	}
	return 0;
}