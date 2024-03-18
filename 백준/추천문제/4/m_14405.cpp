#include <bits/stdc++.h>
using namespace std;
string s;
stack<char> st;

void debug(){
    stack<char> temp;
    temp = st;
    cout << "\n";
    while (temp.size() > 0) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << "\n";
}

bool is_possible() {
    while (st.size() > 0) {
        if (st.size() > 0 && st.top() == 'p') {
            st.pop();
            if (st.size() > 0 && st.top() == 'i') {
                st.pop();
            } else {
                return false;
            }
        } else if (st.size() > 0 && st.top() == 'k') {
            st.pop();
            if (st.size() > 0 && st.top() == 'a') {
                st.pop();
            } else {
                return false;
            }
        } else if (st.size() > 0 && st.top() == 'c') {
            st.pop();
            if (st.size() > 0 && st.top() == 'h') {
                st.pop();
                if (st.size() > 0 && st.top() == 'u') {
                    st.pop();
                } else {
                    return false;
                }
            } else {
                return false;
            }
        } else {
            return false;
        }
        // debug();
    }
    return true;
}

int main() {
    cin >> s;
    for (int i = s.size() - 1; i >= 0; i--) {
        st.push(s[i]);
    }
    if (is_possible()) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}