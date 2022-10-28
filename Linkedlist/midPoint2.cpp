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

node *midpoint(node *head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    node *slow = head;
    node *fast = head->next;

    while (fast != NULL &&  fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

int main()
{
    node *head;
    cin >> head;
    cout << head;
    cout << endl;
    node *mid = midpoint(head);
    cout <<"mid of list : " << mid->data;
    return 0;
}