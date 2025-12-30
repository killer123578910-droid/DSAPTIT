#include<bits/stdc++.h>
using namespace std;
vector<int> ar(100000);
int n;
void in(int k){
    string s;
    string res;
    for(int i=1;i<=k/2;i++){
        s+=to_string(ar[i]);
    }
    res=s;
    int d=0;int c=s.size()-1;
    while(d<c){
        swap(s[d],s[c]);
        d++;c--;
    }
    res+=s;
    cout<<res<<" ";
    n--;
}
void quaylui(int i,int k){
    for(int j=6;j<=8;j+=2){
        if(n==0) break;
        ar[i]=j;
        if(i==k/2) in(k);
        else quaylui(i+1,k);
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        int k=2;
        while(n>0){
            quaylui(1,k);
            k+=2;
        }
        cout<<endl;
    }
    return 0;
}