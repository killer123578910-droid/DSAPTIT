#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        set<char> setl(s.begin(),s.end());
        int need=setl.size();
        int have=0;
        int l=0,r=0;
        vector<int> freq(256,0);
        int res=s.size();
        for(int r=0;r<s.size();r++){
            char c=s[r];
            freq[c]++;
            if(freq[c]==1){
                have++;
            }
            while(have==need){
                res=min(res,r-l+1);
                freq[s[l]]--;
                if(freq[s[l]]==0) have--;
                l++; 
            }
        }
        cout<<res<<endl;
    }
    return 0;
}