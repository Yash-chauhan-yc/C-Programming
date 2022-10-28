#include<iostream>
using namespace std;

void spiral_print(int a[][100], int row, int col)
{
    int sr=0, sc=0, er=row-1, ec=col-1;
    while(sr<=er && sc<=ec)
    {
        for(int row=sr; row<=er; row++)
        {
            cout << a[row][sc] << " ";
        }
        sc++;
        for(int col=sc; col<=ec; col++)
        {
            cout << a[er][col] << " ";
        }
        er--;
        if(sr<er)
        {
            for(int row=er; row>=sr; row--)
            {
                cout << a[row][ec] << " ";
            }
            ec--;
        }
        if(sc<ec)
        {
            for(int col=ec; col>=sc; col--)
            {
                cout << a[sr][col] << " ";
            }
            sr++;
        }
    }
}
int main()
{
    int a[100][100];
    int m,n; 
    cin >> m >> n;
    int val=1;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            a[i][j] = val;
            val++;
        }
    }
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    spiral_print(a,m,n);
    return 0;
}