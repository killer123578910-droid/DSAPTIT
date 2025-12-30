#include<bits/stdc++.h>
using namespace std;
typedef struct node{
    int val;
    node*left;
    node*right;
    node(int x){
        this->val=x;
        this->left=NULL;
        this->right=NULL;
    }
}node;
void makenode(node* root, int x,int y,char z){
    if(root==NULL) return;
    if(root->val==x){
        if(z=='L'){
            root->left=new node(y);
        }else{
            root->right=new node(y);
        }
    }else{
        makenode(root->left,x,y,z);
        makenode(root->left,x,y,z);
    } 
}
int sametree(node* root1,node*root2){
    if(root1==NULL&&root2==NULL){
        return 1;
    }
    if(root1!=NULL&&root2!=NULL){
        return ((root1->val==root2->val)&&sametree(root1->left,root2->left)&&sametree(root1->right,root2->right));
    }
    return 0;
}
int main(){
    int t;cin>>t;
    while(t--){
        int n1,n2;
        node*root1=NULL;
        node*root2=NULL;
        cin>>n1;
        for(int i=0;i<n1;i++){
            int x,y;
            char z;
            cin>>x>>y>>z;
            if(root1==NULL){
                root1=new node(x);
            }
            makenode(root1,x,y,z);
        }
        cin>>n2;
        for(int i=0;i<n2;i++){
            int x,y;
            char z;
            cin>>x>>y>>z;
            if(root2==NULL){
                root2=new node(x);
            }
            makenode(root2,x,y,z);
        }
        cout<<sametree(root1,root2)<<endl;
    }
    return 0;
}