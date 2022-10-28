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

void insert(node *&head, int d)
{
    if (head == NULL)
    {
        head = new node(d);
    }

    node *n = new node(d);
    n->next = head;
    head = n;
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

bool search(node *head, int key)
{
    while (head->next != NULL)
    {
        if(head->data == key)
        {
            return true;
        }
        head = head->next;
    }
    return false;
}

// recursively search
bool recursiveSearch(node*head, int key)
{
    if(head == NULL)
    {
        return false;
    }
    if(head->data == key)
    {
        return true;
    }
    else
    {
        return recursiveSearch(head->next, key);
    }
}

int main()
{
    node *head = NULL;
    insert(head, 4);
    insert(head, 3);
    insert(head, 2);
    insert(head, 1);
    insert(head, 0);
    print(head);
    cout << search(head, 8) << endl;
    cout << recursiveSearch(head, 9);
    return 0;
}