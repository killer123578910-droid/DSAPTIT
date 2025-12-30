#include<bits/stdc++.h>
using namespace std;
typedef struct node{
    int x;
    node* l;
    node* r;
    node(int v){
        x=v;
        l=NULL;
        r=NULL;
    }
}node;
node* makenode(node* root,int k){
    if(root==NULL) return new node(k);
    if(k<root->x){
       root->l= makenode(root->l,k);
    }else{
        root->r= makenode(root->r,k);
    }
    return root;
}
void preor(node * root){
    if(root==NULL) return;
    cout<<root->x<<" ";
    preor(root->l);
    preor(root->r);
}
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int x;
        node*root;
        for(int i=0;i<n;i++){
            cin>>x;
            root=makenode(root,x);
        }
        preor(root);
        cout<<endl;

    }
    return 0;
}