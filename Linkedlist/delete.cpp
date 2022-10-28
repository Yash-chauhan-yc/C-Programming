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

void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << endl;
}

void deleteAtHead(node *&head)
{
    if (head == NULL)
    {
        return;
    }
    node *temp = head->next;
    delete head;
    head = temp;
}


void deleteAtEnd(node *&head)
{
    if(head == NULL)
    {
        return;
    }
    node *temp = head;
    node *prev = head;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    delete temp;
    prev->next = NULL;
}



void deleteAtMiddle(node*&head, int pos)
{
    if(head == NULL)
    {
        return;
    }
    node *temp = head;
    node *prev = head;
    int jump = 1;
    while(jump != pos)
    {
        prev = temp;
        temp = temp->next;
        jump++;
    }
    prev->next = temp->next;
    delete temp;

}

int main()
{
    node *head = NULL;
    insertAtHead(head, 6);
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 0);
    print(head);
    deleteAtHead(head);
    print(head);
    deleteAtEnd(head);
    print(head);
    deleteAtMiddle(head, 3);
    print(head);
    return 0;
}