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

void kFromLast(node *head, int k)
{
    node *temp = head;
    int jump = 1;
    int n = length(head);
    while (jump < n - k + 1)
    {
        temp = temp->next;
        jump++;
    }
    cout << temp->data;
}

void operator>>(istream &is, node *&head)
{
    int x;
    cin >> x;
    head = NULL;
    while (x--)
    {
        int d;
        cin >> d;
        insertAtTail(head, d);
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

int main()
{
    node *head;
    cin >> head;
    int k;
    cin >> k;
    kFromLast(head, k);
    return 0;
}