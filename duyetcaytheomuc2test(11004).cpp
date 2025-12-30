#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int x;
    node *l;
    node *r;
    node(int v)
    {
        x = v;
        l = NULL;
        r = NULL;
    }
} node;
void bfs(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* te=q.front();q.pop();
        cout<<te->x<<" ";
        if(te->l!=NULL){
            q.push(te->l);
        }
        if(te->r!=NULL){
            q.push(te->r);
        }
    }

}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        node *root;
        node *temp;
        node * cur;
        unordered_map<int, node *> maked;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            char z;
            cin >> x >> y >> z;
            if (!maked.count(x))
            {
                root = new node(x);
                temp = new node(y);
                maked[x]=root;
                if (z == 'L')
                {
                    root->l = temp;
                    maked[y] = temp;
                }
                else
                {
                    root->r = temp;
                    maked[y] = temp;
                }
            }
            else
            {
                temp = new node(y);
                if (z == 'L')
                {
                    maked[x]->l = temp;
                    maked[y] = temp;
                }
                else
                {
                    maked[x]->r = temp;
                    maked[y] = temp;
                }
            }
        }
        bfs(root);
        cout<<endl;
    }
    return 0;
}