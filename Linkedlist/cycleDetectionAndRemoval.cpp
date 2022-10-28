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

bool cyclicDetection(node *head)
{
    node *slow = head;
    node *fast = head;
    while (fast != NULL && fast->next == NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

node *cyclicRemoval(node *head)
{
    node *slow = head;
    node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow)
        {
            slow = head;
            break;
        }
    }
    node *prev;
    while(slow == fast)
    {
        slow = slow->next;
        prev = fast;
        fast = fast->next;
    }
    prev->next = NULL;

}

int main()
{
    node *head;
    cin >> head;
    cout << head;
    return 0;
}