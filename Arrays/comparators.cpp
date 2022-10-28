#include<iostream>
using namespace std;

void PrintArray(int a[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout << a[i] << " ";
    }
}

bool compare(int a, int b)
{
    return a>b;
}

void bubble_sort(int a[], int n, bool (&mycompare)(int a, int b))
{
    for(int i=0; i<=n-2; i++)
    {
        for(int j=0; j<=n-2; j++)
        {
            if(compare(a[j], a[j+1]))
            {
                swap(a[j], a[j+1]);
            }
        }
    }
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
    cout << "before swapping ";
    PrintArray(a, n);
    cout << endl;
    cout << "after swapping : ";
    bubble_sort(a, n, compare);
    PrintArray(a,n);

    return 0;
}