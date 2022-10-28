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

bool search(node *root, int k)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->data == k)
    {
        return true;;
    }

    if (k <= root->data)
    {
        return search(root->left, k);
    }
    else
    {
        return search(root->right, k);
    }

}

int main()
{
    node* root = buildTree();
    int k;
    cin >> k;
    if(search(root, k))
    {
        cout << "Present";
    }
    else
    {
        cout << "Not Present";
    }
    return 0;
}