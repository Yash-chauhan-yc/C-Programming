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

node* cyclicDetection(node *head)
{
    node *slow = head;
    node *fast = head;
    while (fast != NULL && fast->next == NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
        {
            return slow;
        }
    }
    return NULL;
}

void cyclicRemoval(node *head)
{
    node *fast = cyclicDetection(head);
    node *slow = head;

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
    node* head;
    cin >> head;
  
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;
  
    cyclicRemoval(head);
  
    cout << "Linked List after removing loop \n";
    cout << head;
    return 0;
}