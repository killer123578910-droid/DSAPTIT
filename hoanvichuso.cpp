#include <bits/stdc++.h>
using namespace std;
int n,b[11];
vector<int> ar(11);
vector<int> a(11);
vector<string> a2;
void in(){
    string temp;
    for(int i=1;i<=n;i++){
        if(temp.size()==0&&a[ar[i]]==0) continue;
        temp+=to_string(a[ar[i]]);
    }
    a2.push_back(temp); 
}
void quaylui(int i){
    for(int j=1;j<=n;j++){
        if(b[j]==0){
            ar[i]=j;
            b[j]=1;
            if(i==n) in(); 
            else quaylui(i+1);
            b[j]=0;
        }
    }
}
int cmp(string a,string b){
    if(a.size()!=b.size()){
        return a.size()<b.size();
    }
    return a<b;
}
int main()
{   
    int t;
    cin>>t;
    while(t--){
    string s;
    cin>>s;
    n=s.size();
    for(int i=0;i<s.size();i++) a[i+1]=s[i]-'0';
    quaylui(1);
    sort(a2.begin(),a2.end(),cmp);
    for(int i=0;i<a2.size();i++) cout<<a2[i]<<endl;
    a2.clear();
    }

    return 0;
}
