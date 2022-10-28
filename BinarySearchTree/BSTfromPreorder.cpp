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

node *construct(int preorder[], int *preorderIdx, int key, int min, int max, int n)
{
    if (*preorderIdx >= n)
    {
        return NULL;
    }

    node* root = NULL;
    if (key > min && key < max)
    {
        root = new node(key);
        *preorderIdx = *preorderIdx + 1;

        if (*preorderIdx < n)
        {
            root->left = construct(preorder, preorderIdx, preorder[*preorderIdx], min, key, n);
        }
        if (*preorderIdx < n)
        {
            root->right = construct(preorder, preorderIdx, preorder[*preorderIdx], key, max, n);
        }
    }
    return root;
}

void printInorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    printInorder(root->left);
    printInorder(root->right);
}

int main()
{
    int preOrder[] = {10, 2, 1, 13, 11};
    int n = 5;
    int preOrderIdx = 0;
    node* root = construct(preOrder, &preOrderIdx, preOrder[0], INT_MIN, INT_MAX, n);
    printInorder(root);
    return 0;
}