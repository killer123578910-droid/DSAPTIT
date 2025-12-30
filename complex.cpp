#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int stt=0 ;
void testcase(){
        int n;
        cin>>n;
        vector<int> ar(n);
        map<int,int> mapl;
        vector<int> res;
        int maxl=0;
        for(int i=0;i<n;i++){
            cin>>ar[i];
            mapl[ar[i]]++;
            maxl=max(maxl,ar[i]);
        }
        for(int i=1;i<=maxl;i++){
            while(mapl[i]--){
                res.push_back(i);
            }
        }
        for(auto x:res) cout<<x<<" ";
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        testcase();
        cout<<endl;
    }
    return 0;
}
