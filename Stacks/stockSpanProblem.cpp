#include <iostream>
#include <stack>
using namespace std;

void stockSpan(int prices[], int n, int span[])
{
    stack<int> s; // indices of the day
    s.push(0);
    span[0] = 1;

    // loop for the rest of days
    for (int i = 0; i <= n - 1; i++)
    {
        int currentprice = prices[i];
        // topmost element that is higher than the current element
        while (!s.empty() && prices[s.top()] <= currentprice)
        {
            s.pop();
        }
        if (!s.empty())
        {
            int prevHighest = s.top();
            span[i] = i - prevHighest;
        }
        else
        {
            span[i] = i + 1;
        }
        s.push(i);
    }
}

int main()
{
    int prices[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(prices) / sizeof(int);
    int span[10000] = {0};
    stockSpan(prices, n, span);
    for (int i = 0; i < n; i++)
    {
        cout << span[i] << " ";
    }
    return 0;
}