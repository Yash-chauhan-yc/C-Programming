#include<iostream>
using namespace std;
bool isSorted(int a[], int n)
{
	if(n==0 || n==1)
	{
		return true;
	}

	bool smallerSorted = isSorted(a+1,n-1);
	if(a[0] < a[1] && smallerSorted)
	{
        return true;
	}
	else
	{
		return false;
	}
}
int main() {
	int a[1000];
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> a[i];
	}
	bool ans = isSorted(a,n);
    if(ans)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

	return 0;
}