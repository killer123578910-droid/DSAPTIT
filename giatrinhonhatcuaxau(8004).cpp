#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, char> a,pair<int, char> b){
    return a.first<b.first;
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int k;
        string s;
        cin >> k >> s;
        map<char,int> freq;
        priority_queue<int> q;
        for(int i=0;i<s.size();i++){
            freq[s[i]]++;
        }
        for(auto x:freq){
            q.push(x.second);
        }
        while(k--){
            if(q.empty()) break;
            auto x=q.top();q.pop();
            x--;
            if(x>0) q.push(x);
        }
        long long sum=0;
        while(!q.empty()){
            sum+=1LL*q.top()*q.top();
            q.pop();
        }
        cout<<sum<<endl;
    }
    return 0;
}