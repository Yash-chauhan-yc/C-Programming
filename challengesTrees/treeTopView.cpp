#include <iostream>
#include <queue>
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
    queue<node *> q;
    int data;
    cin >> data;
    node *root = new node(data);
    while (!q.empty())
    {
        node *front = q.front();
        q.pop();
        int data1, data2;
        cin >> data1 >> data2;
        if (data1 != -1)
        {
            front->left = new node(data1);
            q.push(root->left);
        }
        if (data2 != -1)
        {
            front->right = new node(data2);
            q.push(root->right);
        }
    }
    return root;
}

void topView(node* root)
{
    if(root == NULL)
    {
        return;
    }

    topView(root->left);
    
}

int main()
{

    return 0;
}