#include<bits/stdc++.h>
using namespace std;
int ar[25];
vector<int> a(25);
int n,k;
void in(){
    for(int i=1;i<=k;i++){
        cout<<a[ar[i]]<<" ";
    }
    cout<<endl;
}
void quaylui(int i){
    for(int j=ar[i-1]+1;j<=n-k+i;j++){
        ar[i]=j;
        if(i==k) in();
        else quaylui(i+1);
    }
}
int main(){
    cin>>n>>k;
    map<int,int> mapl;
    int count=1;
    for(int i=1;i<=n;i++){
        int temp;
        cin>>temp;
        if(!mapl.count(temp)){
            a[count]=temp;
            mapl[temp]++;
            count++;
        }
    }
    n=count-1;
    sort(a.begin()+1,a.begin()+n+1);
    cout<<endl;
    quaylui(1);
    return 0;
}