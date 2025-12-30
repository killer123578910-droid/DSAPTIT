#include<bits/stdc++.h>
using namespace std;

void decode() {
    string s; cin >> s;
    stack<string> st1;
    stack<int> st2;

    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            int num = 0;
            while (i < s.size() && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            i--;
            st2.push(num);
        }
        else if (s[i] == ']') {
            string tmp = "";
            while (!st1.empty() && st1.top() != "[") {
                tmp = st1.top() + tmp;
                st1.pop();
            }
            st1.pop(); // pop '['

            int count = st2.top(); st2.pop();
            string expanded = "";
            while (count--) expanded += tmp;

            st1.push(expanded);
        }
        else {
            st1.push(string(1, s[i]));
            if (s[i] == '[' && (i == 0 || !isdigit(s[i - 1]))) {
                st2.push(1);
            }
        }
    }

    string ans = "";
    while (!st1.empty()) {
        ans = st1.top() + ans;
        st1.pop();
    }
    cout << ans;
}
int main(){
    int t;cin>>t;
    while(t--){
        decode();
        cout<<endl;
    }
    return 0;
}
