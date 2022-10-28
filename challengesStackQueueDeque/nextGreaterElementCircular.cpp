#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[10000];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int *nqe = new int[n];
    stack<int> st;

    for (int i = 0; i <= 2 * n - 1; i++)
    {
        

        if (!st.empty() && a[i % n] >= st.top())
        {
            st.pop();
        }


        if (i < n)
        {
            if (!st.empty())
            {
                nqe[i] = st.top();
            }
            else
            {
                nqe[i] = -1;
            }
        }
        st.push(a[i % n]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << nqe[i] << " ";
    }

    return 0;
}