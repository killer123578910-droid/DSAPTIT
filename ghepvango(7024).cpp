    #include<bits/stdc++.h>
    using namespace std;

    int main(){
        int t;cin>>t;
        while(t--){
            int n;cin>>n;
            vector<long long> ar(n);
            for(int i=0;i<n;i++) cin>>ar[i];
            stack<int> st;
            int left[n];
            int right[n];
            for(int i=0;i<n;i++){
                while(!st.empty()&&ar[i]<=ar[st.top()]) st.pop();
                if(st.empty()) left[i]=-1;
                else left[i]=st.top();
                st.push(i);
            }
            while(!st.empty()) st.pop();
            for(int i=n-1;i>=0;i--){
                while(!st.empty()&&ar[i]<=ar[st.top()]) st.pop();
                if(st.empty()) right[i]=n;
                else right[i]=st.top();
                st.push(i);
            }
            long long ans=0;
            for(int i=0;i<n;i++){
                if(right[i]-left[i]-1>=ar[i]){
                    ans=max(ans,ar[i]);
                }
            }
            cout<<ans<<endl;
        }
        return 0;
    }