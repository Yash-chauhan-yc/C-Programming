#include <iostream>
#include <stack>

using namespace std;

class queue
{
private:
    stack<int> s;

public:
    void push(int data)
    {
        s.push(data);
    }

    int pop()
    {
        if (s.empty())
        {
            cout << "Queue is empty";
            return -1;
        }
        int x = s.top();
        s.pop();
        if (s.empty())
        {
            return x;
        }
        int item = pop();
        s.push(x);
        return item;
    }
};

int main()
{
    queue q;
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        q.push(i);
    }
    for(int i=0; i<n; i++)
    {
        cout << q.pop() << " ";
    }
    return 0;
}