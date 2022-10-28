#include <iostream>
#include <stack>
using namespace std;

void postfixEvaluation(string s)
{
    stack<int> st;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            int operand2 = st.top();
            st.pop();
            int operand1 = st.top();
            st.pop();
            switch (s[i])
            {
            case '*' : st.push(operand1*operand2);
                break;
            case '+' : st.push(operand1+operand2);
            break;
            case '-' : st.push(operand1-operand2);
                break;
            case '/' : st.push(operand1/operand2);
                break;
            case '^' : st.push(operand1^operand2);
                break;
            }
        }
    }
    cout << st.top();
}

int main()
{
    postfixEvaluation("46+2/5*7+");
    return 0;
}