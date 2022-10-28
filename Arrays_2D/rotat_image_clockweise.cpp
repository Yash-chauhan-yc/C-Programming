#include<iostream>
using namespace std;

void rotate_clockwise(int a[][100], int row, int col)
{
	for(int i=0; i<col; i++)
	{
		int start=0, end=row-1;
		while(start<end)
		{
			swap(a[start][i], a[end][i]);
			start++;
			end--;
		}
	}
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			if(i<j)
			{
				swap(a[i][j], a[j][i]);
			}
		}
	}
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int a[100][100];
	int row,col;
	cin >> row >> col;
	int val=1;
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			a[i][j] = val;
			val++;
		}
	}
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << "After clockwise rotating : "<< endl;
	rotate_clockwise(a,row,col);
	
	return 0;
}