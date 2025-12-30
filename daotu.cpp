#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin,s);
        stringstream ss(s);
        string temp;
        while(ss>>temp){
            int i=0;int j=temp.size()-1;
            while(i<j){
                swap(temp[i],temp[j]);
                i++;j--;
            }
            cout<<temp<<" ";
        }
        cout<<endl;
    }
    return 0;
}