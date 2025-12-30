#include<bits/stdc++.h>
using namespace std;
typedef struct node{
    int val;
    node* left;
    node* right;
    node(int x){
        this->val=x;
        this->left=NULL;
        this->right=NULL;
    }
}node;
node* root;
int flag1=1;
void makenode(node* root,int x,int y,char z){
    if(root==NULL) return;
    if(root->val==x){
        if(z=='L'){
            root->left=new node(y);
        }else{
            root->right=new node(y);
        }
    }else{
        makenode(root->left,x,y,z);
        makenode(root->right,x,y,z);
    }
}
void checktree(node*root){
    if(root==NULL){
        return;
    }
    if((root->left!=NULL&&root->right==NULL)||(root->left==NULL&&root->right!=NULL)){
        flag1=0;
        return;
    }
    checktree(root->left);
    checktree(root->right);
}
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        root=NULL;
        flag1=1;
        for(int i=0;i<n;i++){
            int x,y;
            char z;
            cin>>x>>y>>z;
            if(root==NULL){
                root=new node(x);
            }
            makenode(root,x,y,z);
        }
        checktree(root);
        if(flag1) cout<<"1"<<endl;
        else cout<<0<<endl;

    }
    return 0;
}