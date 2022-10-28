#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool balancedParenthesis(string s)
{
    stack<char> st;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else
        {
            if (!st.empty() && ((st.top() != '(' && s[i] == ')') || ( st.top() != '{' && s[i] == '}') || (st.top() != '[' && s[i] == ']')))
            {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int main()
{
    string s;
    cin >> s;
    if (balancedParenthesis(s))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}