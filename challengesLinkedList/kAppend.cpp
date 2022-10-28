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

void kappend(node *&head, int k)
{
    int l = length(head);
    int jump = 1;
    node *curr = head;
    node *prev = head;
    while (jump < (l - k + 1))
    {
        prev = curr;
        curr = curr->next;
        jump++;
    }
    prev->next = NULL;
    node *temp = curr;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    head = curr;
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
    kappend(head, k);
    cout << head;
    return 0;
}