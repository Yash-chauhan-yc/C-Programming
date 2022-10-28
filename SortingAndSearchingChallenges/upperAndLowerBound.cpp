#include <iostream>
using namespace std;

int upperBound(int a[], int n, int key)
{
    int s = 0;
    int e = n - 1;
    int ans = -1;
    bool isUpper = false;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (a[mid] == key)
        {
            ans = mid;
            s = mid + 1;
            isUpper = true;
        }
        else if (a[mid] < key)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    if (isUpper)
        return ans;
    else
        return -1;
}

int lowerBound(int a[], int n, int key)
{
    int s = 0;
    int e = n - 1;
    int ans = -1;
    bool islower = false;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (a[mid] == key)
        {
            ans = mid;
            e = mid - 1;
            islower = true;
        }
        else if (a[mid] < key)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    if (islower)
        return ans;
    else
        return -1;
}

int main()
{

    int n;
    cin >> n;
    int a[100000];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int k;
    cin >> k;
    while(k>0)
    {
        int key;
        cin >> key;
        cout << lowerBound(a, n, key) << " " <<  upperBound(a, n, key) << endl;
		k--;
    }
    return 0;
}