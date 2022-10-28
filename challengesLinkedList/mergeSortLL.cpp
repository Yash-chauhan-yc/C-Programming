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

void takeInput(node* &head, int d)
{
    head = NULL;
    while(d--)
    {
        int k;
        cin >> k;
        insertAtTail(head,k);
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


node *midPoint(node *head)
{
    node *slow = head;
    node *fast = head->next;

    while (fast!=NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

node* merge(node*&a, node*&b)
{
    if(a == NULL)
    {
        return b;
    }
    if(b == NULL)
    {
        return a;
    }

    node* c;
    if(a->data < b->data)
    {
        c = a;
        c->next = merge(a->next, b);
    }
    else
    {
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}

node* mergeSort(node*&head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    node* mid = midPoint(head);
    node*a = head;
    node*b = mid->next;
    mid->next = NULL;

    a = mergeSort(a);
    b = mergeSort(b);

    node*c = merge(a,b);
    return c;
}

int main()
{
    
    int n;
    cin >> n;
    node *head;
    takeInput(head, n);
    node *m = mergeSort(head);
    cout << m;
    return 0;
}