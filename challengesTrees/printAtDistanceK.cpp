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

int search(int inorder[], int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}

node *buildTree(int preorder[], int inorder[], int start, int end)
{
    static int idx = 0;
    if (start > end)
    {
        return NULL;
    }

    int curr = preorder[idx];
    idx++;
    node *root = new node(curr);

    int pos = search(inorder, start, end, curr);

    root->left = buildTree(preorder, inorder, start, pos - 1);
    root->right = buildTree(preorder, inorder, pos + 1, end);
    return root;
}

void printAtKlevel(node *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 1)
    {
        cout << root->data << " ";
    }

    printAtKlevel(root->left, k - 1);
    printAtKlevel(root->right, k - 1);
}

int printAtDistanceK(node *root, int key, int k)
{
    if (root == NULL)
    {
        return -1;
    }

    if (root->data == key)
    {
        printAtKlevel(root, k);
    }

    int DL = printAtDistanceK(root->left, key, k);
    if (DL != -1)
    {
        if (DL + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printAtKlevel(root, k - 2 - DL);
        }
        return DL + 1;
    }

    int DR = printAtDistanceK(root->right, key, k);

    if (DR != -1)
    {
        if (DR + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printAtKlevel(root, k - 2 - DR);
        }
        return DR + 1;
    }
    return -1;
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
    int inorder[1000];
    for (int i = 0; i < n; i++)
    {
        cin >> inorder[i];
    }
    node *root = buildTree(preorder, inorder, 0, n - 1);

    int test;
    cin >> test;
    while (test--)
    {
        int data, k;
        cin >> data;
        cin >> k;
        printAtDistanceK(root, data, k);
        cout << endl;
    }
    return 0;
}