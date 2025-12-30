#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node* node;
node makeNode(int x){
    Node *temp=new Node();
    temp->data=x;
    temp->next=NULL;
    return temp;
}
bool empty(node a){
    return a==NULL;
}
int size(node a){
    int cnt=0;
    while(a!=nullptr){
        a=a->next;
        cnt++;
    }
    return cnt;
}
void insertf(node &a,int x){
    node temp=makeNode(x);
    if(a==NULL){
        a=temp;
    }else{
        temp->next=a;
        a=temp;
    }
}
void insertl(node &a,int x){
    node temp=makeNode(x);
    if(a==NULL){
        a=temp;
    }else{
        node p=a;
        while(p->next!=nullptr){
            p=p->next;
        }
        p->next=temp;
    }
}
void insertmid(node &a,int x, int pos){
    int n=size(a);
    for(int i=0;i<pos;i++){
        
    }
}
int main()
{

    return 0;
}