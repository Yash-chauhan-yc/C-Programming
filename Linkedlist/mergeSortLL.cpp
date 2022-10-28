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
    }

    node *n = new node(d);
    n->next = head;
    head = n;
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

ostream &operator<<(ostream &os, node *head)
{
    while (head->next != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    return os;
}

node *midpoint(node *head)
{
    if (head->next == NULL || head == NULL)
        return head;

    node *slow = head;
    node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

node *merge(node *&a, node *&b)
{
    if(a == NULL)
    {
        return b;
    }
    if(b == NULL)
    {
        return a;
    }

    node*c;
    if(a->data < b->data)
    {
        c = a;
        c->next= merge(a->next, b);
    }
    else
    {
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}

node* mergeSort(node*head)
{
    // base case
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    node* mid = midpoint(head);
    node *a = head;
    node *b = mid->next;
    mid->next = NULL;

    a = mergeSort(a);
    b = mergeSort(b);

    node *c = merge(a, b);
    return c;

}

int main()
{
    node *head;
    cin >> head;
    cout << head << endl;
    node* sort = mergeSort(head);
    cout << sort;
    return 0;
}