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

node* buildTree()
{
    int d;
    cin >> d;
    if(d==-1)
    {
        return NULL;
    }
    node*root = new node(d);
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

    return 1 + height(root->left) + height(root->right);
}

class Pair
{
public:
    int height;
    bool balanced;
};

Pair isBalanced(node* root)
{
    Pair p;
    if(root == NULL)
    {
        p.height = 0;
        p.balanced = true;
        return p;
    }

    Pair left = isBalanced(root->left);
    Pair right = isBalanced(root->right);

    p.height = max(left.height, right.height) + 1;

    if(abs(left.height - right.height) <= 1 && left.balanced && right.balanced)
    {
        p.balanced = true;
    }
    else
    {
        p.balanced = false;
    }
    return p;

}

int main()
{
    node* root = buildTree();
    if(isBalanced(root).balanced)
    {
        cout << "balanced";
    }
    else
    {
        cout << "not balanced";
    }
    
    return 0;
}