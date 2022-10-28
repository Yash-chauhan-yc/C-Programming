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

int search(int inOrder[], int start, int end, int curr)
{
    for(int i=start; i<=end; i++)
    {
        if(inOrder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}
node* buildTree(int inOrder[], int preOrder[], int start, int end)
{
    static int idx = 0;
    if(start>end)
    {
        return NULL;
    }
    int curr = preOrder[idx];
    idx++;

    node* root = new node(curr);

    if(start == end)
    {
        return root;
    }

    int pos = search(inOrder, start, end, curr);
    root->left = buildTree(inOrder, preOrder, start, pos-1);
    root->right = buildTree(inOrder, preOrder, pos+1, end);
    return root;
}

void print(node *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL)
    {
        cout << "END => ";
    }
    else
    {
        cout << root->left->data << " => ";
    }
    cout << root->data;
    if (root->right == NULL)
    {
        cout << " <= END" << endl;
    }
    else
    {
        cout << " <= " << root->right->data;
    }
    print(root->left);
    print(root->right);
}

int main()
{
    int n;
    cin >> n;
    int preorder[1000];
    for (int i = 0; i < n; i++)
    {
        cin >> preorder[i];
    }
    int m;
    cin >> m;
    int inorder[1000];
    for (int i = 0; i < m; i++)
    {
        cin >> inorder[i];
    }

    node *root = buildTree(inorder, preorder, 0, n - 1);
    print(root);
    return 0;
}