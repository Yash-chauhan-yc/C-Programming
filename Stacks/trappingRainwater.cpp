#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int rainwater(int a[])
{
    stack<int> s;
    int n = sizeof(n) / sizeof(int);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && a[s.top()] < a[i])
        {
            int curr = s.top();
            s.pop();

            if (s.empty())
            {
                break;
            }
            int diff = i - s.top() - 1;
            ans += (min(a[s.top()], a[i]) - a[curr]) * diff;
        }
        s.push(i);
    }
    return ans;
}

int main()
{
    int a[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << rainwater(a);
    return 0;
}