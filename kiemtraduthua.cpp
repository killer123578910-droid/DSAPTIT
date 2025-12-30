#include <bits/stdc++.h>
using namespace std;

bool checkDuThua(string s){
    stack<char> st;
    for (char c : s){
        if (c != ')'){
            st.push(c); // day cac ki tu != ) vao stack
        }
        else{
            bool coToanTu = false;
            while (!st.empty() && st.top() != '('){
                if (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/'){
                    coToanTu = true;
                }
                st.pop(); // lien tuc xoa cho toi khi gap (
            }
            if (!st.empty()) st.pop();
            if (!coToanTu) return true; // neu giua ( va ) khong co ki tu nao thi co nghia la thua
        }
    }
    return false; // khong tim duoc ngoac thua
}

int main(){
    int test;
    cin >> test;
    cin.ignore();
    while (test--){
        string s;
        getline(cin, s);
        if (checkDuThua(s)) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}