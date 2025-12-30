#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> req;
        int rq;
        int num;
        queue<int> qu;
        for(int i=0;i<n;i++){
            cin>>rq;
            if(rq==1){
                cout<<qu.size()<<endl;
            }else if(rq==2){
                cout<<(qu.empty()?"YES":"NO")<<endl;
            }else if(rq==3){
                cin>>num;
                qu.push(num);
            }
            else if(rq==4){
                if(!qu.empty()) qu.pop();
            }else if(rq==5){
                cout<<(qu.empty()?-1:qu.front())<<endl;
            }else if(rq==6){
                cout<<(qu.empty()?-1:qu.back())<<endl;
            }
        }
        
    }
    return 0;
}