#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
string xoaso(string s){
    string res;
    if(s.empty()) return "0";
    long long i=0;
   while (i < s.size() && s[i] == '0') {
        i++;
    }
    for(long long j=i;j<s.size();j++){
        res.push_back(s[j]);
    }
    if(res.empty()) res="0";
    return res;

}

    void testcase()
{   
    string s;
    string temp;
    string max = "";

    while (getline(cin, s)) {
        stringstream ss(s);
        while (ss >> temp) {
            string cleaned = xoaso(temp); 

            if (cleaned.size() > max.size()) {
                max = cleaned;
            } else if (cleaned.size() == max.size()) {
                if (cleaned > max) max = cleaned;
            }
        }
    }
    cout << max;
}

int main()
{
    
        testcase();

    return 0;
}
