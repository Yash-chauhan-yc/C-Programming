#include<iostream>
#include<algorithm>
using namespace std;
int Triplet(int a[], int n, int sum)
{
	sort(a, a+n);
	for(int i=0; i<n; i++)
	{
        int l=i+1;
        int r=n-1;
		int temp = sum-a[i];
		while(l<r)
		{
			if(a[l] + a[r] == temp)
			{
				cout << a[i] << ", " << a[l] << " and " << a[r] << endl;
				l++;
				r--;
			}
			if(a[l] + a[r] > temp)
			{
				r--;
			}
			if(a[l] + a[r] < temp)
			{
				l++;
			}
		}
	}
    return 0;
}
int main() {
	int n; 
	cin >> n;
	int a[n];
	for(int i=0; i<n; i++)
	{
		cin >> a[i];
	}
	int x;
	cin >> x;
	Triplet(a, n, x);
	return 0;
}