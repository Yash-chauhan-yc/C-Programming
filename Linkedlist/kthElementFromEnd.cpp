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

int length(node *head)
{
    int count = 0;
    while (head->next != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

void kFromEnd1(node *head, int k)
{
    int jump = 1;
    int n = length(head);
    node *temp = head;
    while (jump < n - k + 1)
    {
        temp = temp->next;
        jump++;
    }   
    cout << temp->data;
}

int main()
{
    node *head = NULL;
    cin >> head;
    cout << head;
    cout << endl;
    cout << length(head) << endl;
    kFromEnd1(head, 3);
    return 0;
}