#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int> a(11);vector<int> ar(11);
void quaylui(int i){
	for(int j=a[i-1]+1;j<=n;j++){
		a[i]=j;
		if(i==k) {
			if(ar[a[k]]-ar[a[1]]>k){
				for(int l=1;l<=k;l++){
					cout<<ar[a[l]]<<" ";
				}
				cout<<endl;
			}
		}
		quaylui(i+1);
	}
}

int main(){
	int t;cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) cin>>ar[i];
		sort(ar.begin()+1,ar.begin()+n+1);
		quaylui(1);
	}
	return 0;
}
