#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int k;cin>>k;
        string s;cin>>s;
        unordered_map<char,int> freq;
        for(int i=0;i<s.size();i++){
            freq[s[i]]++;
        }
        priority_queue<int> q;
        for(auto x:freq){
            q.push(x.second);
        }
        while(k--){
            int te=q.top();q.pop();
            if(te>1){
                q.push(--te);
            }
        }
        long long sum=0;
        while(!q.empty()){
            sum+=(1LL*q.top()*q.top());
            q.pop();
        }
        cout<<sum<<endl;
    }
    return 0;
}