#include<iostream>
#include<string>
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
    string val;
    cin >> val;
    node* root = new node(d);
    if(val == "true")
    {
        root->left = buildTree();
    }
    cin >> val;
    if(val == "true")
    {
        root->right = buildTree();
    }
    return root;
}

bool isBalanced(node* root)
{
    int height;
    if(root == NULL)
    {
        height = 0;
        return true;
    }

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);

    height = max(left, right) + 1;
    if(abs(left-right) <= 1 && isBalanced(root->left) && isBalanced(root->right))
    {
        return true;
    }
    return false;
}

int main()
{
    node* root = buildTree();
    if(isBalanced(root))
    {
        cout << "TRUE";
    }
    else
    {
        cout << "FALSE";
    }
    return 0;
}