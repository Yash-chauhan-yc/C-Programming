#include<iostream>
using namespace std;

void rotateImage(int arr[][100], int row, int col)
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++) 
        {
            if(i<j)
            {
                swap(arr[i][j],arr[j][i]);
            }
        }
    }
   
    for(int i=0; i<col; i++)
    {
        int start=0, end=row-1;
        while(start<end)
        {
            swap(arr[start][i], arr[end][i]);
            start++;
            end--;
        }
    }
    
    cout << "After rotating : "<< endl;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int arr[100][100];
    int row,col;
    cin >> row >> col;
    int val=1;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            arr[i][j] = val;
            val++;
        }
    }
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    rotateImage(arr, row, col);

    
}