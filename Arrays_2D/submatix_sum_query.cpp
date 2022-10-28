#include<iostream>
using namespace std;

int sum_submatrices(int a[][100], int row, int col, int ti, int tj, int bi, int bj)
{
    int sum=0;
    for(int i=ti; i<=bi; i++)
    {
        for(int j=tj; j<=bj; j++)
        {
            int tl=(ti+1)*(tj+1);
            int br=(row-bi)*(col-bj);
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
    int tli,tlj,bri,brj;
    cin >> tli >> tlj >> bri >> brj;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << sum_submatrices(a,row,col,tli,tlj,bri,brj);
    return 0;
}