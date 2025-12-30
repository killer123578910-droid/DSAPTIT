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
node* makenode(vector<int> &ar,int i,int n){
    if(i>=n) return NULL;
    
    node* root=new node(ar[i]);
    root->l=makenode(ar,2*i+1,n);
    root->r=makenode(ar,2*i+2,n);
    return root;
}
void preor(node * root){
    if(root==NULL) return;
    preor(root->l);
     cout<<root->x<<" ";
    preor(root->r);
   
}
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> ar(n);
        node*root;
        for(int i=0;i<n;i++){
            cin>>ar[i];
        }
        root=makenode(ar,0,n-1);
        preor(root);
        cout<<endl;

    }
    return 0;
}