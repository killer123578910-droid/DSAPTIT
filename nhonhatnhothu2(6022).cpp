#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        set<int> setl;
        for(int i=0;i<n;i++){
            int num;cin>>num;
            setl.insert(num);
        }
        if(setl.size()<=1){
            cout<<-1<<endl;
        }else{
                auto it=setl.begin();
                auto it1=it++;
                cout<<*it1<<" "<<*it<<endl;
          
        }
    }
    return 0;
}