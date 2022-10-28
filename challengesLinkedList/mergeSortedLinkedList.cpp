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

void insertAtTail(node *&head, int d)
{
    if (head == NULL)
    {
        head = new node(d);
        return;
    }

    node *n = new node(d);
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void takeInput(node *&head, int d)
{
    head = NULL;
    while (d--)
    {
        int k;
        cin >> k;
        insertAtTail(head, k);
    }
}

void operator<<(ostream &os, node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

node *merge(node *&a, node *&b)
{
    if (a == NULL)
    {
        return b;
    }
    else if (b == NULL)
    {
        return a;
    }

    node *c;
    if (a->data < b->data)
    {
        c = a;
        c->next = merge(a->next, b);
    }
    else
    {
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}

int main()
{
    int n1;
    int n2;
    node *head1;
    node *head2;
    cin >> n1;
    takeInput(head1, n1);
    cin >> n2;
    takeInput(head2, n2);
    node *c = merge(head1, head2);
    cout << c;
    return 0;
}