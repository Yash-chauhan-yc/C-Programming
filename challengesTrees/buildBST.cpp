#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node*left;
    node* right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* buildTree(int *arr, int s, int e)
{
    if(s>e)
    {
        return NULL;
    }

    int mid = (s+e)/2;
    node* root = new node(arr[mid]);

    root->left = buildTree(arr, s, mid-1);
    root->right = buildTree(arr, mid+1, e);

    return root;
}

void preorder(node* root)
{
    if(root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[10000];
        for(int i=0; i<n; i++)
        {
            cin >> arr[i];
        }
        int s = 0;
        int e = n-1;
        node* root = buildTree(arr, s, e);
        preorder(root);
        cout << endl;
    }

    return 0;
}