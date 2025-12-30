#include <bits/stdc++.h>
using namespace std;
const long long modd = 1e9 + 7;
int n;
vector<vector<long long>> multi(vector<vector<long long>> &v1,vector<vector<long long>> &v2)
{
    vector<vector<long long>> res(n, vector<long long>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                res[i][j] = (res[i][j] % modd + (v1[i][k] * v2[k][j]) % modd)%modd;

            }
        }
    }
    return res;

}
vector<vector<long long>> donvi;
void init(int n){
    donvi.assign(n,vector<long long>(n,0));
    for(int i=0;i<n;i++){
        donvi[i][i]=1;
    }
}
vector<vector<long long>> luythua(vector<vector<long long>> &v1, long long k,int n)
{
    if(k==0) return donvi;
    vector<vector<long long>> kq=luythua(v1,k/2,n);
    if(k%2==0){
        return multi(kq,kq);
    }
    else{
        kq=multi(kq,kq);
        return multi(v1,kq);
    }
}
void testcase(){
    long long k;
    cin>>n>>k;
    init(n);
    vector<vector<long long>> ar(n,vector<long long>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>ar[i][j];
        }
    }
    vector<vector<long long>> res=luythua(ar,k,n);
    long long sum=0;
    for(int i=0;i<n;i++){
            sum=(sum%modd+res[i][n-1]%modd)%modd;
        }
    cout<<sum<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        testcase();
    }
    return 0;
}