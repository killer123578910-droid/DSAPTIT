#include <bits/stdc++.h>
using namespace std;

long long expo(long long a, long long n)
{
    if (n == 0)
        return 1;
    long long x = expo(a, n / 2);
    if (n % 2 == 0)
        return (x*x);
    return (a*x*x);
}
long long souoc(long long n){
    long long count=0;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            count++;
            if(i*i!=n){
                count++;
            }
        }
        
    }
    return count;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    long long n;
    cin>>n;
    long long i=1;
    long long temp=0;
    while(1){
        if(temp==n){
            i--;
           cout<<i<<endl;
            break;
        }
        if(temp>n){
           cout<<-1<<endl;
            break;
        }
        temp=expo(i,souoc(i));
       
        i++;
    }
    return 0;
}