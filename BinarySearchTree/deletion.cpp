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

node *deleteBST(node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (key < root->data)
    {
        root->left = deleteBST(root->left, key);
        return root;
    }
    else if( key == root->data)
    {
        // found the node to delete (3 case)

        // 1. node with 0 children (leaf node)
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 2. node with 1 children
        if(root->left != NULL || root->right == NULL)
        {
            node* temp = root->left;
            delete root;
            return temp;
        }
        if(root->right != NULL || root->left == NULL)
        {
            node* temp = root->right;
            delete root;
            return temp;
        }

        // 3. node with 2 children
            node* replace = root->right;

            // find the inorder successor from right subtree
            while(replace->left != NULL)
            {
                replace = replace->left;
            }

            root->data = replace->data;
            root->right = deleteBST(root->right, replace->data);
            return root;
    }
    else
    {
        root->right = deleteBST(root->right, key);
        return root;
    }
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

int main()
{
    node *root = buildTree();
    printInorder(root);
    cout << endl;

    int d;
    cin >> d;
    root = deleteBST(root, d);
    printInorder(root);
    return 0;
}