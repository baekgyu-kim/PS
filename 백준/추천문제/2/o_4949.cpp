// 균형잡힌 세상

#include <bits/stdc++.h>
using namespace std;

vector<string> strings;

string is_balanced(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            if (st.empty() == true) {
                return "no";
            } else {
                if (st.top() == '(') {
                    st.pop();
                } else {
                    return "no";
                }
            }
        } else if (c == '[') {
            st.push(c);
        } else if (c == ']') {
            if (st.empty() == true) {
                return "no";
            } else {
                if (st.top() == '[') {
                    st.pop();
                } else {
                    return "no";
                }
            }
        } else {
            continue;
        }
    }
    if (st.empty() == true) {
        return "yes";
    } else {
        return "no";
    }
}

int main() {
    string s = "";
    while (true) {
        getline(cin, s);
        if (s == ".") {
            break;
        } else {
            s.pop_back();
            strings.push_back(s);
        }
    }
    for (int i = 0; i < strings.size(); i++) {
        cout << is_balanced(strings[i]) << "\n";
    }
    return 0;
}