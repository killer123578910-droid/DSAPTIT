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
vector<int> ar1;
void ino(node* root){
    if(root==NULL) return;
    
    ino(root->left);
    ar1.push_back(root->val);
    ino(root->right);
    
}
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        root=NULL;
        vector<int> ar(n);
        ar1.clear();
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            ar[i]=x;
            root=makenode(root,x);
        }
        ino(root);
        if(ar1==ar) cout<<1<<endl;
        else cout<<0<<endl;
    }
    return 0;
}