#include <iostream>
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

    if (d == -1)
    {
        return NULL;
    }

    node *root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

class Pair
{
public:
    int diamter;
    int height;
};

Pair fastDiamter(node *root)
{
    Pair p;
    if (root == NULL)
    {
        p.diamter = p.height = 0;
        return p;
    }

    Pair left = fastDiamter(root->left);
    Pair right = fastDiamter(root->right);

    p.height = max(left.height, right.height) + 1;
    p.diamter = max((left.height + right.height), max(left.diamter, right.diamter));
    return p;
}

int main()
{
    node* root = buildTree();
    Pair p = fastDiamter(root);
    cout << " height of tree : " << p.height << endl;
    cout << " diameter of tree : " << p.diamter;
    return 0;
}