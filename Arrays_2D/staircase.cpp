#include<iostream>
using namespace std;

void stairCase(int arr[][100], int row, int col, int key)
{
    int i=0, j=col-1;
    bool isKeyPresent = false;
    while(i<row && j>=0)
    {
        if(arr[i][j] == key)
        {
            cout << "using stairCase found at index : " << i << " " << j;
            isKeyPresent = true;
            break;
        }
        else if(arr[i][j] < key)
        i++;
        else
        j--;
    }
    if(isKeyPresent == false)
    cout << "Key not found using staircase";
}

void binarysearch(int arr[][100], int row, int col, int key)
{
    bool isKeyPresent = false;
    for(int i=0; i<row; i++)
    {
        int start=0, end=col-1;
        while(start<=end)
        {
            int mid = (start+end)/2;
            if(arr[i][mid] == key)
            {
                cout << "using binarySearch found at index : "<< i << " " << mid;
                isKeyPresent = true;
                break;
            }
            else if(key < arr[i][mid])
            end=mid-1;
            else
            start=mid+1;
        }
    }
    if(isKeyPresent == false)
    cout << "Key not found using binary search";
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
            cout << arr[i][j] <<" ";
        }
        cout << endl;
    }

    int x;
    cin >> x;
    stairCase(arr, row, col, x);
    cout << endl;
    binarysearch(arr, row, col, x);
    return 0;
}