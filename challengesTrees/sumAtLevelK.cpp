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

node *buildtree(node *root, int n)
{

    int num;

    int d;
    cin >> d;
    cin >> n;

    root = new node(d);
    if (n == 0)
        return root;

    if (n >= 1)
    {
        root->left = buildtree(root->left, n);
        n--;
    }

    if (n > 0)
    {
        root->right = buildtree(root->right, n);
        n--;
    }
    return root;
    //  return root;
}

int sumAtKLevel(node *root, int k)
{
    int sum;
    if (root == NULL)
    {
        return 0;
    }
    if (k == 0)
    {
        return root->data;
    }
    int left = sumAtKLevel(root->left, k-1);
    int right = sumAtKLevel(root->right, k-1);

    return left+right;
}

int main()
{
    node *root = NULL;
    root = buildtree(root, 3);
    int k;
    cin >> k;
    int d = sumAtKLevel(root, k);
    // printit(root);
    cout << d;
    return 0;
}