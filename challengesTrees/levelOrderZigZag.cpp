#include <iostream>
#include <string>
#include <algorithm>
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

node *buildTree()
{
    int d;
    cin >> d;
    string val;
    node *root = new node(d);
    if (val == "true")
    {
        root->left = buildTree();
    }
    cin >> val;
    if (val == "true")
    {
        root->right = buildTree();
    }
    return root;
}

void printKlevel(node *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k % 2 != 0)
    {
        if (k == 0)
        {
            cout << root->data << " ";
        }
        printKlevel(root->right, k - 1);
        printKlevel(root->left, k - 1);
    }
    if (k % 2 == 0)
    {
        if (k == 0)
        {
            cout << root->data << " ";
        }
        printKlevel(root->left, k - 1);
        printKlevel(root->right, k - 1);
    }
}

int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    return max(left, right) + 1;
}

void printAllLevel(node *root)
{
    int h = height(root);
    for (int i = 0; i < h; i++)
    {
        printKlevel(root, i);
    }
}

int main()
{
    node *root = buildTree();
    printAllLevel(root);
    return 0;
}