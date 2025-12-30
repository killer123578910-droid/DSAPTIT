#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int stt=0 ;

int main()
{
        int n;
        cin>>n;
        vector<int> ar(n);
        for(int i=0;i<n;i++){
            cin>>ar[i];
        }
        int mini;
        stack<vector<int>> s;
        vector<int> temp1(1);
        temp1[0]=ar[0];
        s.push(temp1);
        int j;
        for(int i=1;i<n;i++){
            int key=ar[i];
            j=i-1;
            while(j>=0&&ar[j]>key){
                ar[j+1]=ar[j];
                j--;
            }
            ar[j+1]=key;
            vector<int> temp(ar.begin(),ar.begin()+i+1);
            s.push(temp);
            stt++;   
        }
        
        while(!s.empty()){
            vector<int> temp2=s.top();
            string str=to_string(stt--);
            cout<<"Buoc "<<str<<": ";
            for(auto x:temp2) cout<<x<<" ";
            cout<<endl;
            s.pop();
        }

        
    return 0;

}
