#include <iostream>
#include <algorithm>
using namespace std;

int maxHouses(int houses[], int nhouses, int budget)
{
    int ans = 0;
    for (int i = 0; i < nhouses - 1; i++)
    {
        for (int j = 0; j < nhouses - 1; j++)
        {
            if (houses[j] > houses[j+1])
                swap(houses[j], houses[j+1]);
        }
    }
    for (int i = 0; i < nhouses; i++)
    {
        cout << houses[i] << " ";
    }
    cout << endl;
    int count=0;
    for(int i=0; i<nhouses; i++)
    {
        ans += houses[i];
        if(ans <= budget)
        {
            count++;
        }
        else
        {
            break;
        }
    }
    return count;
}

int main()
{
    int a[] = {999, 990, 999, 990};
    int n = sizeof(a) / sizeof(int);
    int b;
    cin >> b;
    cout << maxHouses(a, n, b);
    return 0;
}