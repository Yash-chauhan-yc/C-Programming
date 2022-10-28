#include<iostream>
using namespace std;

int main()
{
    int a[100], n;
    cout << "Enter the number of elements : ";
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cout << "Enter the element " << i <<" ";
        cin >> a[i];
    }
    int key, i;
    cout << "Enter the key you want to found : ";
    cin >> key;
    for(i=0; i<n; i++)
    {
        if(a[i]==key)
        {
            cout << "key found at index " << i;
            break;
        }
    }
    if(i == n)
    {
        cout << "Key not found";
    }
    return 0;
}