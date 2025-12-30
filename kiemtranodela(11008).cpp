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
void makenode(node *root, int u, int v, char x)
{
    if (root == NULL)
    {
        return;
    }
    if (root->val == u)
    {
        if (x == 'L')
        {
            node *temp = new node(v);
            root->left = temp;
        }
        else
        {
            node *temp = new node(v);
            root->right = temp;
        }
    }
    else
    {
        makenode(root->left, u, v, x);
        makenode(root->right, u, v, x);
    }
}
void dfs(node *root,int cap1)
{
    if(root==NULL) return;
    cap[root]=cap1;
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
            int x, y;
            char z;
            cin >> x >> y >> z;
            if (root == NULL)
            {
                root = new node(x);
            }
            makenode(root, x, y, z);
        }
        dfs(root,cap1);
        int flag = 1;
        int captieuchuan = 0;
        for (auto x : cap)
        {
            if (x.first->left == NULL && x.first->right == NULL)
            {
                captieuchuan = x.second;
                break;
            }
        }
        for (auto x : cap)
        {
            if (x.first->left == NULL && x.first->right == NULL)
            {
                if (x.second != captieuchuan)
                {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}