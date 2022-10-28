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
    while (d != -1)
    {
        insertAtHead(head, d);
        cin >> d;
    }
    return is;
}

void reverse(node *&head)
{
    node *curr = head;
    node *prev = NULL;
    node *n;

    while (curr != NULL)
    {
        // save the next node
        n = curr->next;
        // make the curr node point to prev
        curr->next = prev;
        // update prev and curr and take them 1 step forwar
        prev = curr;
        curr = n;
    }
    head = prev;
}

node *recursiveReverse(node *&head)
{
    // base case
    if (head->next == NULL || head == NULL)
    {
        return head;
    }
    // recursive case
    node *shead = recursiveReverse(head->next);

    node *temp = shead;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    head->next = NULL;
    temp->next = head;
    return shead;
}

node* optimizedRecReverse(node*&head)
{
    if(head->next == NULL || head == NULL)
    {
        return head;
    }

    node*shead = optimizedRecReverse(head->next);
    node *temp = head->next;
    temp->next = head;
    head->next = NULL;
    return shead;
}

int main()
{
    node *head;
    cin >> head;
    cout << head;
    head = optimizedRecReverse(head);
    cout << head;

    return 0;
}