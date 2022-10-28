#include<iostream>
#include<cstring>
using namespace std;
void magicalPark(char a[][100], int m, int n, int k, int s)
{
    bool success = true;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(s<k)
            {
                success = false;
                break;
            }
            if(a[i][j] == '.')
            {
                s-=2;
            }
            else if(a[i][j] == '*')
            {
                s+=5;
            }
            else
            {
                break;
            }
            if(j!=n-1)
            {
                s--;
            }
        }
    }
    if(success ==  true)
    {
        cout << "Yes" << endl;
        cout << s;
    }
    else
    {
        cout << "No";
    }
}
int main()
{
    char a[100][100];
    int m,n,s,k;
    cin >> m >> n >> k >> s;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> a[i][j];
        }
    }
    magicalPark(a,m,n,k,s);
    return 0;
}