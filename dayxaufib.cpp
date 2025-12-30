    #include<bits/stdc++.h>
    using namespace std;
    vector<unsigned long long> ar(93);
    char getchar(int n,unsigned long long j){
        if(n==1) return 'A';
        if(n==2) return 'B';
        if(j<=ar[n-2]){//
            return getchar(n-2,j);
        }else{
            return getchar(n-1,j-ar[n-2]);
        }
    }
    int main(){
        
        ar[1]=1;
        ar[2]=1;
        for(int i=3;i<93;i++){
            ar[i]=ar[i-2]+ar[i-1];
        }

        int t;
        cin>>t;
        while(t--){
            int n;unsigned long long j;
            cin>>n>>j;
            cout<<getchar(n,j)<<endl;
        }
        return 0;

    }