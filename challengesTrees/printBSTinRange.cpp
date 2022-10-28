#include <iostream>
#include<climits>
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

node *construct(int preorder[], int *preorderIdx, int key, int min, int max, int n)
{
    if (*preorderIdx >= n)
    {
        return NULL;
    }

    node* root = NULL;
    if (key > min && key < max)
    {
        root = new node(key);
        *preorderIdx = *preorderIdx + 1;

        if (*preorderIdx < n)
        {
            root->left = construct(preorder, preorderIdx, preorder[*preorderIdx], min, key, n);
        }
        if (*preorderIdx < n)
        {
            root->right = construct(preorder, preorderIdx, preorder[*preorderIdx], key, max, n);
        }
    }
    return root;
}

void printPreorder(node* root)
{
    if(root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printRange(node* root, int k1, int k2)
{
    if(root == NULL)
    {
        return;
    }

    printRange(root->left, k1, k2);
    
    if(root->data <= k2 && root->data >=k1)
    {
        cout << root->data << " ";
    }

    printRange(root->right, k1, k2);

}

int main()
{
    int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int preorder[100];
		for(int i=0; i<n; i++)
		{
			cin >> preorder[i];
		}
        
		int preorderIdx = 0;
    	node* root = construct(preorder, &preorderIdx, preorder[0], INT_MIN, INT_MAX, n);
		cout << "# Preorder : ";
    	printPreorder(root);
    	cout << endl;
        int k1, k2;
        cin >> k1 >> k2;
		cout << "# Nodes within range are : ";
    	printRange(root, k1, k2);
	}	

    return 0;
}