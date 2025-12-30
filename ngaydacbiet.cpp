#include<bits/stdc++.h>
using namespace std;
int x[9];
vector<string> st;
void in(){
    if(x[1]==0&&x[2]==0) return;
    if(x[3]==0&&x[4]==0) return;
    if(x[5]==0) return;
    if(x[3]==2) return;
    //if(!doixung()) return;

    string temp;
    for(int i=1;i<=2;i++) temp+=to_string(x[i]);
    temp+="/";
    for(int i=3;i<=4;i++) temp+=to_string(x[i]);
    temp+="/";
    for(int i=5;i<=8;i++) temp+=to_string(x[i]);
    st.push_back(temp);
}
void quaylui(int i){
    for(int j=0;j<=2;j+=2){
        x[i]=j;
        if(i==8) in();
        else quaylui(i+1);
    }
}
int main(){
    quaylui(1);
    sort(st.begin(),st.end());
    for(auto x:st) cout<<x<<endl;
    return 0;
}