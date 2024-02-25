// 괄호

#include <bits/stdc++.h>
using namespace std;

int T = 0;
vector<string> strings;

string is_correct(string s) {
    stack<char> st;
    for (char c : s) {
        if(c == '('){
            st.push(c);
        }else{
            if(st.empty() == true){
                return "NO";
            }else{
                st.pop();
            }
        }
    }
    if(st.empty() == true){
        return "YES";
    }else{
        return "NO";
    }
}

int main() {
    cin >> T;
    string s;
    for (int i = 0; i < T; i++) {
        cin >> s;
        strings.push_back(s);
    }
    for (int i = 0; i < T; i++) {
        s = strings[i];
        cout << is_correct(s) << "\n";
    }
    return 0;
}