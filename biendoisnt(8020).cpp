#include<bits/stdc++.h>
using namespace std;
vector<int> cnt(10000,0);
bool cnte(int x){
    for(int i=2;i<=sqrt(x);i++){
        if(x%i==0) return false;
    }
    return true;
}
void init(){
    for(int i=1000;i<=9999;i++){
        if(cnte(i)){
            cnt[i]=1;
        }else{
            cnt[i]=0;
        }
    }
}
int main(){
    int t;cin>>t;
    init();
    while(t--){
        string s,t;
        cin>>s>>t;
        unordered_map<string,int> dist;
        queue<string> q;
        q.push(s);
        dist[s]=0;
        while(!q.empty()){
            string te=q.front();q.pop();
            if(te==t) break;
            string newte;
            for(int i=0;i<=3;i++){
                for(int j=0;j<=9;j++){
                    newte=te;
                    if(i==0&&j==0) continue;
                    newte[i]=j+'0';
                    if(!dist.count(newte)&&cnt[stoi(newte)]){
                        q.push(newte);
                        dist[newte]=dist[te]+1;
                    }
                }
            } 
        }
        cout<<dist[t]<<endl;
    }
    return 0;
}