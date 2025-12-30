#include<bits/stdc++.h>
using namespace std;
vector<long long> leng(93);
void init(){
    leng[1]=1;
   for(int i=2;i<93;i++){
    leng[i]=leng[i-1]*2+1;
   } 
}
char kitu(int n,long long k){
    long long mid=leng[n]/2;
    mid++;
    if(k<mid){
        return kitu(n-1,k);
    }
    if(k>mid){
        return kitu(n-1,k-mid);
    }else{
        return 'A'+n-1;
    }

}
void testcase(){
    int n;
    long long k;
    cin>>n>>k;
    cout<<kitu(n,k)<<endl;
}
int main(){
    init();
    int t;
    cin>>t;
    while(t--){
        testcase();
    }
    return 0;
}