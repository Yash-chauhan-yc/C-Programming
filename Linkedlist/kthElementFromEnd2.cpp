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

void kFromEnd(node*head, int k)
{
    node*fast = head;
    node*slow = head;
    node*temp = head;
    
    
    while(k--)
    {
        fast = fast->next;
    }
    while(fast->next!=NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    cout << slow->data;
}

int main()
{
    node *head = NULL;
    cin >> head;
    cout << head;
    cout << endl;
    kFromEnd(head, 4);
    return 0;
}