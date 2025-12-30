#include<bits/stdc++.h>
using namespace std;

int main(){
        int n;
        cin>>n;
        vector<string> req;
        string rq;
        int num;
        deque<int> qu;
        for(int i=0;i<n;i++){
            cin>>rq;
            if(rq=="PUSHFRONT"){
                cin>>num;
                qu.push_front(num);
            }
            else if(rq=="POPFRONT"){
                if(!qu.empty()) qu.pop_front();
            }else if(rq=="PRINTFRONT"){
                if(!qu.empty()) cout<<qu.front()<<endl;
                else cout<<"NONE"<<endl;
            }else if(rq=="PUSHBACK"){
                cin>>num;
                qu.push_back(num);
            }else if(rq=="POPBACK"){
                if(!qu.empty()) qu.pop_back();
            }else if(rq=="PRINTBACK"){
                if(!qu.empty()) cout<<qu.back()<<endl;
                else cout<<"NONE"<<endl;
            }
        }
    return 0;
}