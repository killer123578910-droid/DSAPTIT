#include<bits/stdc++.h>
using namespace std;
typedef struct node{
    int data;
    struct node* right;
    struct node* left;
}*Tree;
void init(Tree* T){
    *T=NULL;
}
Tree getNode(){
    Tree p;
    p=new node;
    return p;
}
void freenode(Tree p){
    delete(p);
}
int isempty(Tree *T){
    if(*T==NULL) return 1;
    return 0;
}
Tree makeNode(int x){
    Tree p;
    p=getNode();
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}
Tree searcht(Tree T,int x){
    Tree p;
    if(T->data==x){
        return T;
    }
    if(T==NULL) return NULL;
    p=searcht(T->left, x);
    if(p==NULL){
        p=searcht(T->right,x);
    }
    return p;
}
