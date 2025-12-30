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
int flag1=1,flag2=1,cap=1;
unordered_map<node*,int> mcap;
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
void checktree(node*root,int cap){
    if(root==NULL){
        return;
    }
    mcap[root]=cap;
    if((root->left!=NULL&&root->right==NULL)||(root->left==NULL&&root->right!=NULL)){
        flag1=0;
        return;
    }
    checktree(root->left,cap+1);
    checktree(root->right,cap+1);
}
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        root=NULL;
        cap=1;
        flag1=1,flag2=1;
        mcap.clear();
        for(int i=0;i<n;i++){
            int x,y;
            char z;
            cin>>x>>y>>z;
            if(root==NULL){
                root=new node(x);
            }
            makenode(root,x,y,z);
        }
        checktree(root,cap);
        int tieuchuan;
        for(auto x:mcap){
            if (x.first->left == NULL && x.first->right == NULL){
                tieuchuan=x.second;
                break;
            }
        }  
        for(auto x:mcap){
            if (x.first->left == NULL && x.first->right == NULL){
                if(tieuchuan!=x.second){
                    flag2=0;
                    break;
                }
            }
        }
        if(flag1&&flag2) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;

    }
    return 0;
}