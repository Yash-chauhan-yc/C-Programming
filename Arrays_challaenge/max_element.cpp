#include<iostream> 
using namespace std;

void MaxDigit(int a[], int n)
{ 
    int max = a[0];
	for(int i=0; i<n; i++)
	{
		if(a[i] > max)
		{
			max = a[i];
    	}
	}
	cout<<max;

}
int main() {
    int a[] = {1,2,3,4,5};
    int n = sizeof(a)/sizeof(int);
	MaxDigit(a,n);
	return 0;
}