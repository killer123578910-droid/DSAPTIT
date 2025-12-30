#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector <char> chu_cai;
vector <int>  chu_so;

void sinh_chuoi_so(int vtrihtai, string &htai, vector<string> &tboso, char max_digit){
    if(vtrihtai == n) {
        tboso.push_back(htai);
        return;
    }
    for (char c = '1'; c<=max_digit; c++){
        htai.push_back(c);
        sinh_chuoi_so(vtrihtai + 1, htai, tboso, max_digit);
        htai.pop_back();
    }
}
int main(){
    cin >> n;
    char max_digit = '0' + n;
    chu_cai.resize(n);
    for (int i=0; i<n; i++){
        chu_cai[i] = 'A' + i;
    }
    sort(chu_cai.begin(), chu_cai.end());
    vector<string> tboso;
    string temp = "";
    sinh_chuoi_so(0, temp, tboso, max_digit);
    do{
        for ( auto &s : tboso){
            for (char c : chu_cai){
                cout << c;
            }cout << s <<endl;
        }
    } while(next_permutation(chu_cai.begin(), chu_cai.end()));
    return 0;
}