#include<bits/stdc++.h>
using namespace std;
void hanoitower(int n,char A,char B,char C){
    if(n==1){
        cout<<A<<" -> "<<B<<endl;
        return;
    }
    hanoitower(n-1,A,C,B);
    cout<<A<<" -> "<<B<<endl;
    hanoitower(n-1,C,B,A);
}
int main(){
    int n;
    cin>>n;
    hanoitower(n,'A','C','B');
    return 0;

}