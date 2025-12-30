#include<bits/stdc++.h>
using namespace std;
vector<string> st(31);
int n;int k;
int a[31];
vector<string> res;
void in(){
    string temp;
    for(int i=1;i<=k;i++){
        temp+=st[a[i]];
        temp+=" ";
    }
    res.push_back(temp);
}
void quaylui(int i){
    for(int j=a[i-1]+1;j<=n-k+i;j++){
        a[i]=j;
        if(i==k) in();
        else quaylui(i+1);
    }
}


int main(){
    cin>>n>>k;
    int cont=1;
    map<string,int> mapl;
    string temp;
    for(int i=1;i<=n;i++){
        cin>>temp;
        if(!mapl.count(temp)){
            st[cont]=temp;
            mapl[temp]++;
            cont++;
        }
    }
    n=cont-1;
    sort(st.begin()+1,st.begin()+n+1);
    quaylui(1);
    sort(res.begin(),res.end());
    for(auto x:res) cout<<x<<endl;
   return 0;     
}