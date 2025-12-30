#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    int n;
    int ar[]={1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
    while(t--){
        cin>>n;
        int to=0;
        for(int i=9;i>=0;i--){
            if(n>=ar[i]){
                while(n>=ar[i]){
                    to++;
                    n-=ar[i]
                }
            }
        }
        cout<<to<<endl;
    }
}