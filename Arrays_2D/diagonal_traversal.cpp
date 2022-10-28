#include<iostream>
using namespace std;
int diagonal_traversal(int arr[][100],int m, int n)
{
	int b[100];
	bool up=true;
	int i=0;
	int row =0, col=0;
	while(row<m && col<n)
	{
		if(up)
		{
			while(row>=0 && col<n-1)
			{
				b[i] = arr[row][col];
				i++;
				row--;
				col++;
			}
			b[i++] = arr[row][col];
			if(col == n-1)
			row++;
			else
			col++;
		}
		else{
			while(col>=0 && row<m-1)
			{
				b[i] = arr[row][col];
				i++;
				col--;
				row++;
			}
			b[i++] =  arr[row][col];
			if(row==m-1)
			col++;
			else
			row--;
		}
		up=!up;
	}
	return arr;
}
int main() {
	int a[];
	int row, col;
	cin >> row >> col;
	for(int i=0; i<row*col; i++)
	{
		cin >> a[i];
	}
	diagonal_traversal(a);
	return 0;
}