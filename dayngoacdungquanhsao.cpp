#include<bits/stdc++.h>
using namespace std;
int main(){

    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin,s);
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                count++;
            }else if(s[i]==')'){
                count--;
            }else{
                break;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}