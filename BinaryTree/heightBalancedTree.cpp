#include<iostream>
#include<algorithm>
using namespace std;

class node
{
public:
    int data;
    node* left; 
    node* right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node*buildTree()
{
    int d;
    cin >> d;
    if(d==-1)
    {
        return NULL;
    }

    node* root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

int height(node* root)
{
    if(root == NULL)
    {
        return 0;
    }

    int h1 = height(root->left);
    int h2 = height(root->right);
    return max(h1,h2) + 1;
}

bool heightBalancedTree(node*root)
{
    if(root == NULL)
    {
        return true;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if(abs(leftHeight - rightHeight) <= 1 && heightBalancedTree(root->left) && heightBalancedTree(root->right))
    {
        return true;
    }
    return false;
}

int main()
{
    node* root = buildTree();
    cout << " Height of tree : " << height(root) << endl;   
    if(heightBalancedTree(root))
    {
        cout << "It is height balanced Tree";
    }
    else
    {
        cout << "It is not height balanced Tree";
    }
    return 0;
}