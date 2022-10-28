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
    node*n = new node(d);
    node*temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

node* kReverse(node *&head, int k)
{
    node *prevptr = NULL;
    node *curr = head;
    node *nextptr;
    int jump = 0;
    while (curr != NULL && jump < k)
    {
        nextptr = curr->next;
        curr->next = prevptr;
        prevptr = curr;
        curr = nextptr;
        jump++;
    }

    if(nextptr!=NULL)
    {
        head->next = kReverse(nextptr,k);
    }
    return prevptr;
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

void takeInput(node* &head, int d)
{
    head = NULL;
    while(d--)
    {
        int k;
        cin >> k;
        insertAtHead(head,k);
    }
}

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    node *head = NULL;
    takeInput(head,n);
    node* newhead = kReverse(head, k);
    cout << newhead;
    return 0;
}