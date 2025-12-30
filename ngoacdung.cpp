    #include<bits/stdc++.h>
    using namespace std;
    int valid(char a,char b){
        if(a=='('){
            return (b==')');
        }
        if(a=='['){
            return (b==']');
        }
        if(a=='{'){
            return (b=='}');
        }
    }
    int main(){
        int t;
        cin>>t;
        cin.ignore();
        while(t--){
            string s;
            getline(cin,s);
            stack<char> st;
            int flag=1;
            for(int i=0;i<s.size();i++){
                if(s[i]=='('||s[i]=='['||s[i]=='{'){
                    st.push(s[i]);
                }else if(st.empty()&&(s[i]=='}'||s[i]==']'||s[i]==')')){
                    flag=0;
                    break;
                }else if(!st.empty()&&valid(st.top(),s[i])){
                    st.pop();
                }else{
                    flag=0;
                }
            }
            if(st.empty()&&flag==1) cout<<"true"<<endl;
            else cout<<"false"<<endl;
        }
        return 0;
    }