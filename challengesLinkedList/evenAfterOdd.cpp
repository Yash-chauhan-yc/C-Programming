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

node* evenAfterOdd(node *&head)
{
    node *even;
    node *odd;
    node *e;
    node *o;
    node *temp = head;
    while (temp->next != NULL)
    {
        if ((temp->data % 2) != 0)
        {
            if (odd == NULL)
            {
                odd = temp;
                o = odd;
            }
            else
            {
                o->next = temp;
                o = o->next;
            }
        }
        else
        {
            if (even == NULL)
            {
                even = temp;
                e = even;
            }
            else
            {
                e->next = temp;
                e = e->next;
            }
        }
        temp = temp->next;
    }
    o->next = even;
    e->next = NULL;
    return odd;
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
    node* ans = evenAfterOdd(head);
    cout << ans;
    return 0;
}