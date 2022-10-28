#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *insertBST(node *root, int data)
{
    if (root == NULL)
    {
        return new node(data);
    }

    if (data <= root->data)
    {
        root->left = insertBST(root->left, data);
    }

    if (data >= root->data)
    {
        root->right = insertBST(root->right, data);
    }
    return root;
}

node *buildTree()
{
    int d;
    cin >> d;

    node *root = NULL;
    while (d != -1)
    {
        root = insertBST(root, d);
        cin >> d;
    }
    return root;
}

void printInorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

class linkedList
{
public:
    node *head;
    node *tail;
};

linkedList flattenBST(node* root)
{
    linkedList l;
    if(root == NULL)
    {
        l.head = l.tail = NULL;
        return l;
    }

    // leaf node
    if(root->left == NULL && root->right == NULL)
    {
        l.head = l.head = root;
        return l;
    }

    // if left subtree is not NULL
    if(root->left != NULL && root->right == NULL)
    {
        linkedList leftLL = flattenBST(root->left);
        leftLL.tail->right = root;

        l.head = leftLL.head;
        l.tail = root;
        return l;
    }

    // if right subtree is not NULL
    if(root->right != NULL && root->left == NULL)
    {
        linkedList rightLL = flattenBST(root->right);
        root->right = rightLL.head;

        l.head = root;
        l.tail = rightLL.tail;
        return l;
    }

    // both sides are not NULL
    linkedList leftLL = flattenBST(root->left);
    linkedList rightLL = flattenBST(root->right);

    leftLL.tail->right = root;
    root->right = rightLL.head;

    l.head = leftLL.head;
    l.tail = rightLL.tail;
    return l;
}

int main()
{
    node *root = buildTree();
    printInorder(root);
    cout << endl;
    linkedList L = flattenBST(root);
    node* temp = L.head;
    while(temp!=NULL)
    {
        cout << temp->data << "-->";
        temp = temp->right;
    }
    return 0;
}