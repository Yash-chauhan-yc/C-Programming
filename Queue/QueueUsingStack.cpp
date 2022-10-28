#include <iostream>
#include <stack>
using namespace std;

class Queue
{
private:
    stack<int> s1;
    stack<int> s2;

public:
    void push(int x)
    {
        s1.push(x);
    }

    void pop()
    {
        if(s1.empty() && s2.empty())
        {
            cout << "queue is empty";
            return;
        }
        if(s2.empty())
        {    
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        cout << s2.top();
        s2.pop();
        cout << endl;
    }

    bool empty()
    {
        return s1.empty() && s2.empty();
    }

};

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.pop();
    q.push(5);
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    return 0;
}