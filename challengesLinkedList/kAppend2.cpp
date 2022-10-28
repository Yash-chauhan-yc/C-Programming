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

int length(node *head)
{
    int len = 0;
    while (head != NULL)
    {
        head = head->next;
        len++;
    }
    return len;
}

node *kappend(node *&head, int k)
{
    node *newhead;
    node *newtail;
    node *tail = head;
    int n = length(head);
    int count = 1;
    k = k % n;
    while (tail->next != NULL)
    {
        if (count == n - k)
            newtail = tail;
        if (count == n - k + 1)
            newhead = tail;

        tail = tail->next;
        count++;
    }
    newtail->next = NULL;
    tail->next = head;

    return newhead;
}

void operator>>(istream &is, node *&head)
{
    int x;
    cin >> x;
    head = NULL;
    while (x--)
    {
        int d;
        cin >> d;
        insertAtTail(head, d);
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

int main()
{
    node *head;
    cin >> head;
    int k;
    cin >> k;

    node *append = kappend(head, k);
    cout << append;
    return 0;
}