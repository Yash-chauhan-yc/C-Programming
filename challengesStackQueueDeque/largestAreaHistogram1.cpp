#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

int largetRectangularArea(vector<int> heights)
{
    int n = heights.size();
    stack<int> st;

    int leftSmaller[n], rightSmaller[n];
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[i] <= heights[st.top()])
        {
            st.pop();
        }

        if (st.empty())
        {
            leftSmaller[i] = 0;
        }
        else
        {
            leftSmaller[i] = st.top() + 1;
        }
        st.push(i);
    }

    while (!st.empty())
    {
        st.pop();
    }

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && heights[i] <= heights[st.top()]
        )
        {
            st.pop();
        }
        if (st.empty())
        {
            rightSmaller[i] = n - 1;
        }
        else
        {
            rightSmaller[i] = st.top() - 1;
        }
        st.push(i);
    }

    int maxA = 0;
    for (int i = 0; i < n; i++)
    {
        maxA = max(maxA, heights[i] * (rightSmaller[i] - leftSmaller[i] + 1));
    }
    return maxA;
}

int main()
{
    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.push_back(x);
    }
    cout << largetRectangularArea(s);
    return 0;
}