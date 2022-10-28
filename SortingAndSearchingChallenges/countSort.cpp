#include<iostream>
#include<climits>
using namespace std;

void countSort(int a[], int n)
{
    int i,j;
    int max = INT_MIN;
    for(i=0; i<n; i++)
    {
        if(max < a[i])
        max = a[i];
    }
    cout << max << endl;
    int *freq = new int[1000000]{0};

    for(i=0; i<n; i++)
    {
        freq[a[i]] = freq[a[i]] + 1;
    }

    for(i=0; i<n; i++)
    {
        cout << freq[i];
    }
    cout << endl;
    i=0; 
    j=0;
    while(j<=max)
    {
        if(freq[j]>0)
        {
            a[i] = j;
            freq[j]--;
            i++;
        }
        else
        {
            j++;
        }
    }
    for(i=0; i<n; i++)
    {
        cout << a[i];
    }
    delete []freq;

}
int main()
{
    int n;
    cin >> n;
    int a[100];
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    countSort(a,n);
    return 0;
}