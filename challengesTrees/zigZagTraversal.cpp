#include <iostream>
#include <string>
#include <stack>
#include <vector>
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
    node *root = new node(d);

    string val;
    cin >> val;
    if (val == "true")
    {
        root->left = buildTree();
    }
    cin >> val;
    if (val == "true")
    {
        root->right = buildTree();
    }
    return root;
}

void zizagtraversal(node *root)
{
    // if null then return
    if (!root)
        return;

    // declare two stacks
    stack<node*> currentlevel;
    stack<node *> nextlevel;

    // push the root
    currentlevel.push(root);

    // check if stack is empty
    bool lefttoright = true;
    while (!currentlevel.empty())
    {

        // pop out of stack
        node *temp = currentlevel.top();
        currentlevel.pop();

        // if not null
        if (temp)
        {

            // print the data in it
            cout << temp->data << " ";

            // store data according to current
            // order.
            if (lefttoright)
            {
                if (temp->left)
                    nextlevel.push(temp->left);
                if (temp->right)
                    nextlevel.push(temp->right);
            }
            else
            {
                if (temp->right)
                    nextlevel.push(temp->right);
                if (temp->left)
                    nextlevel.push(temp->left);
            }
        }

        if (currentlevel.empty())
        {
            lefttoright = !lefttoright;
            swap(currentlevel, nextlevel);
        }
    }
}

void printPreorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main()
{
    node *root = buildTree();
    printPreorder(root);
    cout << endl;
    zizagtraversal(root);
    return 0;
}