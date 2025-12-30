#include<bits/stdc++.h>
using namespace std;
void tescase(){
    int n;
    cin>>n;
    int count=0;
    vector<int> ar(n);
    vector<int> b(n);
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }

    for(int i=0;i<n;i++){
        int k=i;
        for(int j=i+1;j<n;j++){
            if(ar[j]<ar[k]) k=j;
        }
        if(k!=i){
            count++;
            swap(ar[i],ar[k]);
        }
        
    }
    cout<<count<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        tescase();
    }
    return 0;
}