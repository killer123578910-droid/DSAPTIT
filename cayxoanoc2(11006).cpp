#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
    int x;
    node* l;
    node* r;
    node(int v){
        x=v;
        l=NULL;
        r=NULL;
    }
}node;
void spiral(node* root){
    if(root==NULL) return;
    stack<node*> s1;
    stack<node*> s2;
    s1.push(root);
    while(!s1.empty()||!s2.empty()){
        while(!s1.empty()){
            node* temp=s1.top();s1.pop();
            cout<<temp->x<<" ";
            if(temp->r!=NULL){
                s2.push(temp->r);
            }
            if(temp->l!=NULL){
                s2.push(temp->l);
            }
        }
        while(!s2.empty()){
            node* temp=s2.top();s2.pop();
            cout<<temp->x<<" ";
            if(temp->l!=NULL){
                s1.push(temp->l);
            }
            if(temp->r!=NULL){
                s1.push(temp->r);
            }
        }
    }
}

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        node* root;
        node* temp;
        unordered_map<int,node*> m;
        for(int i=0;i<n;i++){
            int x,y;char z;
            cin>>x>>y>>z;
            temp=new node(y);
            if(!m.count(x)){
                root=new node(x);
                m[x]=root;
                if(z=='L'){
                    root->l=temp;
                    m[y]=temp;
                }else if(z=='R'){
                    root->r=temp;
                    m[y]=temp;
                }
            }else{
                if(z=='L'){
                    m[x]->l=temp;
                    m[y]=temp;
                }else if(z=='R'){
                    m[x]->r=temp;
                    m[y]=temp;
                }
            }

        }
        spiral(root);
        cout<<endl;
    }
    return 0;
}