    #include <bits/stdc++.h>
    using namespace std;

    vector<long long> mergre(vector<long long> &lef, vector<long long> &right)
    {   

        vector<long long> ar(lef.size()+right.size());
        int l = lef.size();
        int r = right.size();
        int i = 0, j = 0, k = 0;

        while (i < l && j < r)
        {
            if (lef[i] < right[j])
                ar[k++] = lef[i++];
            else
                ar[k++] = right[j++];
        }
        while (i < l)
            ar[k++] = lef[i++];
        while (j < r)
            ar[k++] = right[j++];
        return ar;
    }
    void testcase(){
        int n,m;
        cin >> n>>m;
        vector<long long> ar(n),b(m);
        for (int i = 0; i < n; i++)
            cin >> ar[i];
        for(int i=0;i<m;i++){
            cin>>b[i];
        }
        sort(ar.begin(),ar.end());
        sort(b.begin(),b.end());
        vector<long long> res=mergre(ar,b);
        for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
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
