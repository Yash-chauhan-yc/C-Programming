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
    node *n = new node(d);
    node *temp = head;

    n->next = head;
    if(temp!=NULL)
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
    else
    {
        n->next = n;
    }
    head = n;
}

void deleteAtHead(node*&head)
{
    if(head == NULL)
    {
        return;
    }
    node*temp1 = head->next;
    node*temp = head;
    while(temp->next!=head)
    {
        temp = temp->next;
    }
    
    temp->next = temp1;
    head = temp1;
    delete head;
}

void deleteAtEnd(node*&head)
{
    node*temp = head;
    node*prev;
    while(temp->next!=head)
    {
        prev = temp;
        temp = temp->next;
    }
    delete temp;
    prev->next = head;

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
    node *temp = head;
    while (temp->next != head)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << temp->data;
    return os;
}

int main()
{
    node *head;
    cin >> head;
    cout << head;
    deleteAtHead(head);
    return 0;
}