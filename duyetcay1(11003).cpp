#include <bits/stdc++.h>
using namespace std;
typedef struct Node
{
    int val;
    Node *left;
    Node *right;

} Node;
Node *makenode(int x)
{
    Node *temp=new Node;
    temp->val = x;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}
vector<int> in, pre;
unordered_map<int, int> pos;
int preindx;
Node *buildTree(int inL, int inR)
{
    if (inL > inR)
        return NULL;
    int rootval = pre[preindx++];
    Node *root = makenode(rootval);
    int mid = pos[rootval];
    root->left=buildTree(inL, mid - 1);
    root->right=buildTree(mid+1, inR);
    return root;
}
void postorder(Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        in.resize(n);
        pre.resize(n);
        pos.clear();
        for (int i = 0; i < n; i++)
            cin >> in[i], pos[in[i]] = i;
        for (int i = 0; i < n; i++)
            cin >> pre[i];
        preindx = 0;
        Node *root = buildTree(0, n - 1);
        postorder(root);
        cout << endl;
    }
    return 0;
}