#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        queue<string> qu;
        qu.push("1");
        string temp;
        for(int i=0;i<n;i++){
            temp=qu.front();
            qu.pop();
            cout<<temp<<" ";
            string s1=temp+"0";qu.push(s1);
            string s2=temp+"1";qu.push(s2);
        }
        cout<<endl;
    }
    return 0;
}