#include <iostream>
#include <deque>
using namespace std;

int main()
{
    int a[10000];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int k;
    cin >> k;

    deque<int> q(k);
    int i;
    for (i = 0; i < k; i++)
    {
        while (!q.empty() && a[i] >= q.front())
        {
            q.pop_front();
        }
        q.push_back(i);
    }

    // processing the remaining elements
    for (; i < n; i++)
    {
        cout << a[q.front()] << " ";

        // remove the element which are not the part of window (contraction)
        while (!q.empty() && (q.front() <= i - k))
        {
            q.pop_front();
        }

        // remove the element which are not useful and are in window
        while (!q.empty() && (a[q.back()] <= a[i]))
        {
            q.pop_back();
        }

        // add the new elements (expansion)
        q.push_back(i);
    }
    cout << a[q.front()];

    return 0;
}