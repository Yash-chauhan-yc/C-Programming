#include<iostream>
using namespace std;

int main()
{
    int a[100], n;
    cout << "Enter the no of elements in array : ";
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cout << "Enter the " << i << " element : ";
        cin >> a[i];
    }
    for (size_t i = 0; i < n-1; i++)
    {
        int min = i;
        for (size_t j = i+1; j < n; j++)
        {
            if(a[j] < a[min])
                swap(a[j], a[min]);       
        }
    }
    for (size_t i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    
    return 0;
}