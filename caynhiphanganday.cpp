#include<bits/stdc++.h>
using namespace std;
typedef struct node{
	int x;
	node* l;
	node* r;
	node(int k){
		x=k;
		l=NULL;
		r=NULL;
	}
}node;
vector<node*> f(200005);
void inor(node* root){
	if(!root) return;
	inor(root->l);
	cout<<root->x<<" ";
	inor(root->r);
}
int main(){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		vector<long long> ar(n+1);
		for(int i=1;i<=n;i++) cin>>ar[i];
		f[1]=new node(ar[1]);
		for(int i=2;i<=n;i++){
			if(i%2==0){
				f[i]=new node(ar[i]);
				f[i/2]->l=f[i];
			}else{
				f[i]=new node(ar[i]);
				f[(i-1)/2]->r=f[i];
			}
		}
		inor(f[1]);
		cout<<endl;
	}
	return 0;
}
