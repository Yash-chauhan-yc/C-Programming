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

node *buildTree(node *root, int data)
{
    if (root == NULL)
    {
        return new node(data);
    }

    if (data <= root->data)
    {
        root->left = buildTree(root->left, data);
    }
    else
    {
        root->right = buildTree(root->right, data);
    }
    return root;
}

node *deleteBST(node *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (data < root->data)
    {
        root->left = deleteBST(root->left, data);
        return root;
    }
    if (data == root->data)
    {
        // 0 children
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 children
        if (root->left != NULL && root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }

        if (root->right != NULL && root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 children
        node *replace = root->right;
        while (replace->left != NULL)
        {
            replace = replace->left;
        }

        root->data = replace->data;
        root->right = deleteBST(root->right, replace->data);
        return root;
    }
    else
    {
        root->right = deleteBST(root->right, data);
        return root;
    }
}

void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[1000];
        node *root = NULL;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            root = buildTree(root, a[i]);
        }

        int m;
        cin >> m;
        int b[100];
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
            root = deleteBST(root, b[i]);
        }
        preorder(root);
        cout << endl;
    }
    return 0;
}