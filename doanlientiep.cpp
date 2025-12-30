#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ar[n];
        for(int i=0;i<n;i++){
            cin>>ar[i];
        }
        vector<int> danhdau(n,0);
        danhdau[0]=1;
        for(int i=1;i<n;i++){
                int j=i-1;
                while(j>=0&&ar[i]>=ar[j]){
                    j-=danhdau[j];
                }
                danhdau[i]=i-j;
        }
        for(auto x:danhdau) cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}