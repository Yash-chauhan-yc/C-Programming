#include<iostream>
using namespace std;

int sum_submatrices(int a[][100], int row, int col)
{
    int sum=0;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            int tl=(i+1)*(j+1);
            int br=(row-i)*(col-j);
            sum += (tl*br) * a[i][j];
        }
    }
    return sum;
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
    cout << sum_submatrices(a,row,col);
    return 0;
}