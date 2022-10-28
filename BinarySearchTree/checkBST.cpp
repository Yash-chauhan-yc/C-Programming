#include<iostream>
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

node* insertBST(node* root, int data)
{
    if(root == NULL)
    {
        return new node(data);
    }

    if(data <= root->data)
    {
        root->left = insertBST(root->left, data);
    }

    if(data >= root->data)
    {
        root->right = insertBST(root->right, data);
    }
    return root;
}


node* buildTree()
{
    int d;
    cin >> d;
    
    node* root = NULL;
    while(d!=-1)
    {
        root = insertBST(root, d);
        cin >> d;
    }
    return root;
}

void printInorder(node* root)
{
    if(root == NULL)
    {
        return;
    }
    
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

bool isBST(node* root, int minV = INT_MIN, int maxV = INT_MAX)
{
    if(root == NULL)
    {
        return true;
    }

    if(root->data >= minV && root->data <= maxV && isBST(root->left, minV, root->data) && isBST(root->right, root->data, maxV))
    {
        return true;
    }
    return false;


}

int main()
{
    node* root = buildTree();
    printInorder(root);
    cout << endl;
    if(isBST(root))
    {
        cout << "It is a BST";
    }
    else
    {
        cout << "It is not a BST";
    }
    return 0;
}