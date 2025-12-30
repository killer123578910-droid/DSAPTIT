#include<bits/stdc++.h>
using namespace std;
typedef struct node{
    int val;
    node* left;
    node* right;
    node(int x){
        this-> val=x;
        this->left=NULL;
        this->right=NULL;
    }
}node;
node* root;
node* makenode(node* root,int x){
    if(root==NULL) return new node(x);
    if(x<root->val){
        root->left=makenode(root->left,x);
    }else{
        root->right=makenode(root->right,x);
    }
    return root;
}
void ino(node* root){
    if(root==NULL) return;
    
    ino(root->left);
    ino(root->right);
    cout<<root->val<<" ";
}
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        root=NULL;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            root=makenode(root,x);
        }
        ino(root);
        cout<<endl;
    }
    return 0;
}