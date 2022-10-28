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

node *buildTree(int *a, int s, int e)
{
    if (s > e)
    {
        return NULL;
    }

    int mid = (s + e) / 2;
    node *root = new node(a[mid]);
    root->left = buildTree(a, s, mid - 1);
    root->right = buildTree(a, mid + 1, e);
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

void modifySum(node* root, int* sum)
{
    if(root == NULL)
    {
        return;
    }

    modifySum(root->right, sum);
    *sum = *sum + root->data;
    root->data = *sum;
    modifySum(root->left, sum);
}

void replaceSum(node* root)
{
    int sum = 0;
    modifySum(root, &sum);
}

int main()
{
    int n;
    cin >> n;

    int a[1000];
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    node*root = buildTree(a, 0, n-1);
    replaceSum(root);
    printInorder(root);
    return 0;
}