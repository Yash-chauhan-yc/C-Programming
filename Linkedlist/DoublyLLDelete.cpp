#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
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
    if (head != NULL)
    {
        head->prev = n;
    }
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
    cout << endl;
    return os;
}

void deleteAtHead(node *&head)
{
    node *temp = head->next;
    delete head;
    head = temp;
}

void deleteAtTail(node *&head)
{
    node *temp = head;
    node *temp1;
    while (temp->next != NULL)
    {
        temp1 = temp;
        temp = temp->next;
    }
    temp1->next = NULL;
    delete temp;
}

void deleteAtMid(node*&head, int pos)
{
    node*temp = head;
    node*temp1;
    int jump = 1;
    while(jump!=pos)
    {
        temp1 = temp;
        temp = temp->next;
        jump++;
    }
    temp1->next = temp->next;
    temp->next->prev = temp1;
    delete temp;
}

int main()
{
    node *head;
    cin >> head;
    cout << head;
    int pos;
    deleteAtMid(head, 3);
    cout << head;
    return 0;
}