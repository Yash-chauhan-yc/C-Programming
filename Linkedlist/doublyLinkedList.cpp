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
    if(head!=NULL)
    {
        head->prev = n;
    }
    head = n;
}

void insertAtTail(node *&head, int d)
{
    if (head == NULL)
    {
        head = new node(d);
    }

    node *n = new node(d);
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    
    temp->next = n;
    n->prev = temp;
}

void insertAtMid(node*&head, int d, int pos)
{
    if(head == NULL)
    {
        head = new node(d);
    }

    node*n = new node(d);
    node*temp = head;
    node*temp1;
    int jump = 1;
    while(jump!=pos)
    {
        temp1 = temp;
        temp = temp->next;
        jump++;
    }
    n->next = temp1->next;
    temp->prev = n;
    temp1->next = n;
    n->prev = temp1;

    
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

int main()
{
    node *head;
    cin >> head;
    cout << head;
    insertAtMid(head, 3, 3);
    cout << head;
    return 0;
}