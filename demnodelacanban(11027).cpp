#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int val;
    node *left;
    node *right;
    node(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
} node;

node *buildTree(vector<int> &ar, int l, int r)
{
    if (l > r)
        return NULL;
    int mid = (l + r) / 2;
    node *ro = new node(ar[mid]);
    ro->left = buildTree(ar, l, mid - 1);
    ro->right = buildTree(ar, mid + 1, r);
    return ro;
}

int tieuchuan = 0;

void preorder(node *root)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        tieuchuan++;
    }
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> ar(n);
        for (int i = 0; i < n; i++)
        {
            cin >> ar[i];
        }

        sort(ar.begin(), ar.end(),greater<int>());
        node *root = buildTree(ar, 0, n - 1);

        tieuchuan = 0;
        preorder(root);

        cout << tieuchuan << endl;
    }
    return 0;
}
