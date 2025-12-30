#include<bits/stdc++.h>
using namespace std;
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    long long n;
    cin>>n;
    string s;
    cin>>s;
    set<string> st;
    string temp="";
    long long count=0;
    for(long long i=0;i<n;i++){
        temp=s;
        temp.erase(remove(temp.begin(),temp.end(),s[i]),temp.end());
        st.insert(temp);
        count++;
    }
    cout<<count-st.size()<<endl;
    return 0;
}