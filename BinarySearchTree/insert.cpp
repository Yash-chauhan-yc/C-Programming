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

// accepts the old root node and data and returns new node
node *insertBST(node *root, int data)
{
    // base case
    if (root == NULL)
    {
        return new node(data);
    }

    // recursive case - insert in the subtree and return the root
    if (data <= root->data)
    {
        root->left = insertBST(root->left, data);
    }

    if (data >= root->data)
    {
        root->right = insertBST(root->right, data);
    }
    return root;
}

node *buildTree()
{
    // read the list till -1 and insert these number in BST
    int d;
    cin >> d;

    node *root = NULL;

    while (d != -1)
    {
        root = insertBST(root, d);
        cin >> d;
    }
    return root;
}

void BFS(node*root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node* f = q.front();
        if(f == NULL)
        {
            cout << endl;
            q.pop();
            if(!q.empty())
            {
                q.push(NULL);

            }
        }
        else
        {
            cout << f->data << " ";
            q.pop();
            if(f->left)
            {
                q.push(f->left);
            }
            if(f->right)
            {
                q.push(f->right);
            }
        }
    }
    return;
}

void inorderPrint(node* root)
{
    if(root== NULL)
    {
        return;
    }

    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main()
{
    node *root = buildTree();
    inorderPrint(root);
    cout << endl;
    BFS(root);
    return 0;
}