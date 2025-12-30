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
int n;
unordered_map<node *, int> cap;
int cap1 = 0;
node* makenode(node *root,int x)
{
    if (root == NULL)
    {
        return new node(x);
    }
    if (x<root->val)
    {
        root->left=makenode(root->left,x);
    }
    else
    {
        root->right=makenode(root->right,x);
    }
    return root;
}
int captieuchuan = 1;
void dfs(node *root,int cap1)
{
    if(root==NULL) return;
    cap[root]=cap1;
    captieuchuan=max(captieuchuan,cap1);
    dfs(root->left,cap1+1);
    dfs(root->right,cap1+1);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        root=NULL;
        cap.clear();
        cap1=0;
        for (int i = 0; i < n; i++)
        {
            
            int x;
            cin>>x;
            root=makenode(root,x);
        }
        dfs(root,cap1);
        cout<<captieuchuan<<endl;
        captieuchuan=1;
    }
    return 0;
}