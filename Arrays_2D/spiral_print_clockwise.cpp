#include<iostream>
using namespace std;

void spiral_print(int a[][100], int m, int n)
{
    int sr=0, er=m-1, sc=0, ec=n-1;
    while(sr<=er && sc<=ec)
    {
        for(int col=sc; col<=ec; col++)
        {
            cout << a[sr][col] << " ";
        }
        sr++;
        for(int row=sr; row<=er; row++)
        {
            cout << a[row][ec] << " ";
        }
        ec--;
        if(sr<er)
        {
            for(int col=ec; col>=sc; col--)
            {
                cout << a[er][col] << " ";
            }
            er--;
        }
        if(sc<ec)
        {
            for(int row=er; row>=sr; row--)
            {
                cout << a[row][sc] << " ";
            }
            sc++;
        }
    }
    cout << endl;
}


int main()
{
    int a[100][100];
    int r,c;
    cin >> r >> c;
    int val = 1;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            a[i][j] = val;
            val++;
        }
    }
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    spiral_print(a,r,c);
    return 0;
}