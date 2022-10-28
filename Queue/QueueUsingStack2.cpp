#include <iostream>
#include <stack>
using namespace std;

class Queue
{
private:
    stack<int> s1;

public:
    void push(int data)
    {
        s1.push(data);
    }

    int pop()
    {
        if(s1.empty())
        {
            cout << "queue is empty";
            return -1;
        }
        int x = s1.top();
        s1.pop();
        if(s1.empty())
        {
            return x;
        }
        int item = pop();
        s1.push(x);
        return item;
    }

    bool empty()
    {
        return s1.empty();
    }

};

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout << q.pop();
    cout << q.pop();
    q.push(5);
    
    return 0;
}