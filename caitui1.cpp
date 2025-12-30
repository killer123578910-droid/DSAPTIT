#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> memo;
int caitui(int value[],int wt[],int n,int w){
    if(n==0||w==0){
        return 0;
    }
    if(memo[n][w]!=-1){
        return memo[n][w];
    }
    if(wt[n-1]>w){
        return memo[n][w]=caitui(value,wt,n-1,w);
    }else{
        return memo[n][w]=max(caitui(value,wt,n-1,w),value[n-1]+caitui(value,wt,n-1,w-wt[n-1]));
    }
}
int main(){
    int n,w;
    cin>>n>>w;
    int value[n];
    int wt[n];
    for(int i=0;i<n;i++){
        cin>>wt[i]>>value[i];
    }
    memo.resize(n + 1, vector<int>(w + 1, -1));
    cout<<caitui(value,wt,n,w);
    return 0;
    
    
}