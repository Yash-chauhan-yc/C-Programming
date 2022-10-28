#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Stack
{
    vector<int> stack;
    vector<int> minStack;
    vector<int> maxStack;

public:
    void push(int data)
    {
        int currentMin = data;
        int currentMax = data;

        if (minStack.size())
        {
            currentMin = min(minStack[minStack.size() - 1], data);
            currentMax = max(minStack[minStack.size() - 1], data);
        }
        minStack.push_back(currentMin);
        maxStack.push_back(currentMax);
        stack.push_back(data);
    }

    int top()
    {
        return stack[stack.size() - 1];
    }

    int getMax()
    {
        return maxStack[maxStack.size() - 1];
    }

    int getMin()
    {
        return minStack[minStack.size() - 1];
    }

    void pop()
    {
        stack.pop_back();
        minStack.pop_back();
        maxStack.pop_back();
    }

    void print()
    {
        for (auto x : stack)
        {
            cout << x << " ";
        }
        cout << endl;
        for (auto x : minStack)
        {
            cout << x << " ";
        }
        cout << endl;
        for (auto x : maxStack)
        {
            cout << x << " ";
        }
        cout << endl;
    }
};


int main()
{
    Stack s;
    s.push(1);
    s.push(3);
    s.push(5);
    s.push(8);
    s.print();
    cout << s.getMax() << endl;
    s.pop();
    cout << s.getMin() << endl;
    cout << s.getMax() << endl;
    s.pop();
    s.pop();
    cout << s.top() << endl;
    cout << s.getMax() << endl;
    return 0;
}