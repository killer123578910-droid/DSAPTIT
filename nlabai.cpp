#include<bits/stdc++.h>
using namespace std;
int cmp(string a,string b){
    return a+b>b+a;
}
int main(){
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    sort(ar,ar+n);
    vector<string> a(3);
    int j=1;
    for(int i=0;i<a.size();i++){
        a[i]=to_string(ar[n-j]);
        j++;
    }
    sort(a.begin(),a.end(),cmp);
    for(auto x:a) cout<<x;
    return 0;
}