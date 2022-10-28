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

node *reverseLL(node *&head)
{
    node *prev = NULL;
    node *curr = head;
    node *n;
    while (curr != NULL)
    {
        n = curr->next;
        curr->next = prev;
        prev = curr;
        curr = n;
    }
    head = prev;
    return head;
}

bool isPalindrome(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return true;
    }
    node *slow = head;
    node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    slow->next = reverseLL(slow->next);

    slow = slow->next;

    node *temp = head;
    while (slow != NULL)
    {
        if (slow->data != temp->data)
        {
            return false;
        }
        temp = temp->next;
        slow = slow->next;
    }
    return true;
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
    bool ans = isPalindrome(head);
    if (ans)
        cout << "true";
    else
        cout << "false";
    return 0;
}