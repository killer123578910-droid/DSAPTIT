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
vector<pair<int,int>> ar;
node* root;

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
void spiralorder(node*root){
    if(root==NULL) return;
    stack<node*> ar1;
    stack<node*> ar2;
    ar1.push(root);
    while(!ar1.empty()||!ar2.empty()){
        while(!ar1.empty()){
            node*temp=ar1.top();
            cout<<temp->val<<" ";
            ar1.pop();
            if(temp->right!=NULL){
                ar2.push(temp->right);
            }
            if(temp->left!=NULL){
                ar2.push(temp->left);
            }
           
        }
        while(!ar2.empty()){
            node*temp=ar2.top();
            cout<<temp->val<<" ";
            ar2.pop();
            
            if(temp->left!=NULL){
                ar1.push(temp->left);
            }
            if(temp->right!=NULL){
                ar1.push(temp->right);
            }
        }

    }
}
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        root=NULL;
        int cap=1;
        ar.clear();
        for(int i=0;i<n;i++){
            int x,y;
            char z;
            cin>>x>>y>>z;
            if(root==NULL){
                root=new node(x);
            }
            makenode(root,x,y,z);
        }
        spiralorder(root);
        cout<<endl;
    }
    return 0;
}