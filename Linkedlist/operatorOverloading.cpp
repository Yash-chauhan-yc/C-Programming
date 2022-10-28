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

void insertAtHead(node *&head, int d)
{
    if (head == NULL)
    {
        head = new node(d);
        return;
    }

    node *n = new node(d);
    n->next = head;
    head = n;
}

node *takeInput()
{
    int d;
    cin >> d;
    node *head = NULL;
    while (d != -1)
    {
        insertAtHead(head, d);
        cin >> d;
    }
    return head;
}

void print(node *head)
{
    while (head->next != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << endl;
}

// operator overloading
ostream &operator<<(ostream &os, node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << endl;
    return os;
}

istream &operator>>(istream &is, node *&head)
{
    int d;
    cin >> d;
    head = NULL;
    while(d!=-1)
    {
        insertAtHead(head, d);
        cin >> d;
    }
    return is;
}

int main()
{
    node *head;
    node *head1;
    cin >> head >> head1;
    cout << head << head1;
    
    return 0;
}