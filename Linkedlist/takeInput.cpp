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
    if(head == NULL)
    {
        head = new node(d);
        return;
    }
    
    node*n = new node(d);
    n->next = head;
    head = n;
}

node *takeInput()
{
    int d;
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

int main()
{
    node *head = takeInput();
    print(head);
    return 0;
}