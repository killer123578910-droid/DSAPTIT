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
int n;
vector<int> in,level;
node* root;
node* build(vector<int> &in, vector<int>&level){
    if(in.empty()||level.empty()) return NULL;
    node* root=new node(level[0]);
    int idx = find(in.begin(), in.end(), root->val) - in.begin();
    vector<int> inL(in.begin(),in.begin()+idx);
    vector<int> inR(in.begin()+idx+1,in.end());

    vector<int> levelL,levelR;
    unordered_set<int> lvl(inL.begin(),inL.end());
    unordered_set<int> lvr(inR.begin(),inR.end());
    for(auto x:level){
        if(lvl.count(x)) levelL.push_back(x);
        else if(lvr.count(x)) levelR.push_back(x);
    }
    root->left=build(inL,levelL);
    root->right=build(inR,levelR);
    return root;
}
void postorder(node* root){
    if(root==NULL) return;
    else{
        postorder(root->left);
        postorder(root->right);
        cout<<root->val<<" ";
    }
}

int main(){
    int t;cin>>t;
    while(t--){
        root=NULL;
        cin>>n;
        level.resize(n);
        in.resize(n);
        for(int i=0;i<n;i++){
            cin>>in[i];
        }
        for(int i=0;i<n;i++) cin>>level[i];
        root=build(in,level);
        postorder(root);
        cout<<endl;
    }
    return 0;
}