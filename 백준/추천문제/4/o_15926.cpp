#include <bits/stdc++.h>

using namespace std;

int N, _max;
string s;
stack<int> st;

void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    cin >> s;
}

int main() {
    input();
    st.push(-1);
    for (int i = 0; i < N; i++) {
        if (s[i] == '(')
            st.push(i);
        if (s[i] == ')') {
            st.pop();
            if (!st.empty()) {
                _max = max(_max, i - st.top());
            } else {
                st.push(i);
            }
        }
    }
    cout << _max << '\n';

    return 0;
}