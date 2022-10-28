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
    q.push(root);
    while (!q.empty())
    {
        node *front = q.front();
        q.pop();

        int data1, data2;
        cin >> data1 >> data2;

        if (data1 != -1)
        {
            front->left = new node(data1);
            q.push(front->left);
        }

        if (data2 != -1)
        {
            front->right = new node(data2);
            q.push(front->right);
        }
    }
    return root;
}

void rightView(node *root)
{
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        int n = q.size();
        for(int i=0; i<n; i++)
        {
            node* front = q.front();
            q.pop();

            if(i == n-1)
            {
                cout << front->data << " ";
            }

            if(front->left)
            {
                q.push(front->left);
            }
            
            if(front->right)
            {
                q.push(front->right);
            }
        }
    }
}

int main()
{
    node* root = buildTree();
    rightView(root);
    return 0;
}