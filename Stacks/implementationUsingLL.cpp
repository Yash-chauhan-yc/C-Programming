#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int d)
    {
        data = d;
        next = NULL;
    }
};
node *top;

void push(int d)
{
    if(top == NULL)
    {
        top = new node(d);
        return;
    }
    node *n = new node(d);
    n->next = top;
    top = n;
}

void display()
{
    node *temp = top;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void pop()
{
    if(top == NULL)
    {
        cout << "stack underflow";
        return;
    }
    node*temp = top->next;
    delete top;
    top = temp;
}

int peek()
{
    if(top == NULL)
    {
        cout << "no element";
        return -1;
    }
    return top->data;
}


int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    display();
    pop();
    display();
    cout << peek();
    return 0;
}