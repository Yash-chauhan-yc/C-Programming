#include <iostream>
#include <queue>
using namespace std;

class stack
{
private:
    queue<int> q1, q2;

public:
    void push(int x)
    {
        q1.push(x);
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        swap(q1, q2);
    }

    void pop()
    {
        q2.pop();
    }

    int top()
    {
        return q2.front();
    }

    int size()
    {
        return q2.size(); 
    }

    bool empty()
    {
        return size() == 0;
    }

};

int main()
{
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();        
    }
    return 0;
}