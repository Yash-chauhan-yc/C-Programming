#include<iostream>
#include<climits> // INT_MAX and INT_MIN
using namespace std;

int main()
{
    int a[100], n;
    cout << "Enter the number of elements : ";
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cout << "Enter the element " << i <<" : ";
        cin >> a[i];
    }
    int max = INT_MIN; // INT_MIN == -2^31
    for (int i = 0; i < n; i++)
    {
        /* code */
        if(a[i] > max)
        {
            max = a[i];
        }
    }
    cout << "Largest number : " << max;
    
    return 0;
}