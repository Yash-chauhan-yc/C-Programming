#include<iostream>
#include<algorithm>
using namespace std;

bool compare(int a, int b)
{
    return a>b;
}
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
    cout << "before sorting : ";
    for(int i=0; i<n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    sort(a, a+n, compare);
    cout << "after sorting : ";
    for (size_t i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    
    return 0;
}