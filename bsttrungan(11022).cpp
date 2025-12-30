#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
    int val;
    node *left;
    node *right;
    node(int x)
    {
        this->val = x;
        this->left = NULL;
        this->right = NULL;
    }
} node;
node *root;
node *makenode(node *root, int x)
{
    if (root == NULL)
        return new node(x);
    if (x < root->val)
        root->left = makenode(root->left, x);
    else
        root->right = makenode(root->right, x);
    return root;
}
int tgian=0;
void dfs(node *root)
{
    if (root == NULL)
        return;
    if (root->left != NULL || root->right != NULL)
        tgian++;

    dfs(root->left);
    dfs(root->right);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        root = NULL;
        int n;
        cin >> n;
        tgian=0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            root = makenode(root, x);
        }
        dfs(root);
        cout <<tgian<< endl;
    }
    return 0;
}