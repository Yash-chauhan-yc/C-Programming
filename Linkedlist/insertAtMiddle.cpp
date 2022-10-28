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

void insertAtTail(node *&head, int d)
{
    if (head == NULL)
    {
        head = new node(d);
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    node *n = new node(d);
    temp->next = n;
}

int length(node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

void insertAtMiddle(node *&head, int pos, int d)
{
    if (head == NULL || pos == 0)
    {
        insertAtHead(head, d);
    }
    else if (pos > length(head))
    {
        insertAtTail(head, d);
    }
    else
    {
        node*temp = head;
        int jump = 1;
        while (jump != pos - 1)
        {
            temp = temp->next;
            jump++;
        }
        node*n = new node(d);
        n->next = temp->next;
        temp->next = n;
    }
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

int main()
{
    node *head = NULL;
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 0);
    print(head);
    insertAtMiddle(head,3,4);
    insertAtTail(head, 8);
    print(head);
    return 0;
}