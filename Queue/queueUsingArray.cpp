#include <iostream>
using namespace std;

class Queue
{
private:
    int *arr;
    int front;
    int back;
    int ms;

public:
    Queue(int ds = 10)
    {
        arr = new int[ds];
        front = -1;
        back = -1;
        ms = ds;
    }

    void push(int data)
    {
        if (back == ms)
        {
            cout << "Queue Overflow";
            return;
        }
        back++;
        arr[back] = data;

        if (front == -1)
        {
            front += 1;
        }
    }

    void pop()
    {
        if (front == -1 || front > back)
        {
            cout << "Queue is empty";
            return;
        }
        front++;
    }

    bool empty()
    {
        return front == -1 || front > back;
    }

    int peek()
    {
        return arr[front];
    }
};

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << q.peek() << endl;
    q.pop();

    cout << q.peek() << endl;
    q.pop();

    cout << q.peek() << endl;
    q.pop();

    cout << q.peek() << endl;
    q.pop();

    cout << q.empty();


    return 0;
}