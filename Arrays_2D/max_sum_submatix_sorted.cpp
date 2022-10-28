#include<iostream>
using namespace std;
int sum_max(int a[][100], int row, int col)
{
    // col wise addition first 
    for(int i=row-1; i>=0; i--)
    {
        for(int j=col-2; j>=0; j--)
        {
            a[i][j] += a[i][j+1];
        }
    }
    //row wise addition
    for(int i=col-1; i>=0; i--)
    {
        for(int j=row-2; j>=0; j--)
        {
            a[j][i] += a[j+1][i];
        }
    }
    int result = INT_MIN;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            result = max(result, a[i][j]);
        }
    }
    return result;
}
int main()
{
    int a[100][100];
    int row,col;
    cin >> row >> col;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << sum_max(a,row,col);
    return 0;
}