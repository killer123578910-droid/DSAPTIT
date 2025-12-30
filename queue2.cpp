#include<bits/stdc++.h>
using namespace std;

int main(){
        int n;
        cin>>n;
        vector<string> req;
        string rq;
        int num;
        queue<int> qu;
        for(int i=0;i<n;i++){
            cin>>rq;
            if(rq=="PUSH"){
                cin>>num;
                qu.push(num);
            }
            else if(rq=="POP"){
                if(!qu.empty()) qu.pop();
            }else if(rq=="PRINTFRONT"){
                if(!qu.empty()) cout<<qu.front()<<endl;
                else cout<<"NONE"<<endl;
            }
        }
    return 0;
}