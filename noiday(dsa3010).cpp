#include<bits/stdc++.h>
using namespace std;
class cmp{
    public:
    bool operator()(int &a,int &b){
        return a>b;
    }
};
void testcase(){
    int n;
    cin>>n;
    vector<int> ar(n);
    priority_queue<int,vector<int>,cmp> pq;
    for(int i=0;i<n;i++){
        cin>>ar[i];
        pq.push(ar[i]);
    }
    int first;
    int second;
    long long sum=0;
    while(pq.size()>1){
        first=pq.top();pq.pop();
        second=pq.top();pq.pop();
        sum+=first+second;
        pq.push(first+second);
    }
    cout<<sum<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        testcase();
    }
    return 0;
}