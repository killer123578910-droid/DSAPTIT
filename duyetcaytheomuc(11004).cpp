#include <bits/stdc++.h>
using namespace std;
int n;

typedef struct node
{
    int val;
    node *right;
    node *left;
} node;
node *root;
node *makenode(int x)
{
    node *temp = new node;
    temp->val = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void insertnode(node *root, int u, int v, char x)
{
    if (root == NULL)
        return;
    else
    {
        if (root->val == u)
        {
            if (x == 'L')
            {
                node *n1 = makenode(v);
                root->left = n1;
            }
            else
            {
                node *n1 = makenode(v);
                root->right = n1;
            }
        }
        else
        {
            insertnode(root->left, u, v, x);
            insertnode(root->right, u, v, x);
        }
    }
}
void bfs(node *root)
{
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *p = q.front();
        q.pop();
        cout << p->val << " ";
        if (p->left != NULL)
        {
            q.push(p->left);
        }
        if (p->right != NULL)
        {
            q.push(p->right);
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        root = NULL;

        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            char z;
            cin >> x >> y >> z;
            if (root == NULL)
            {
                root = makenode(x);
                if (z == 'L')
                {
                    node *n1 = makenode(y);
                    root->left = n1;
                }
                else
                {
                    node *n1 = makenode(y);
                    root->right = n1;
                }
            }
            else
            {
                insertnode(root, x, y, z);
            }
        }
        bfs(root);
        cout << endl;
    }

    return 0;
}