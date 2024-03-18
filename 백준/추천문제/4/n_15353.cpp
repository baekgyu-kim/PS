#include <bits/stdc++.h>
using namespace std;
string s1, s2;
bool carry = 0;
int a = 0;
int b = 0;
int res = 0;
stack<int> st;
int main() {
    cin >> s1 >> s2;
    int s1_size = s1.size();
    int s2_size = s2.size();
    int _max = max(s1_size, s2_size) - 1;
    for (int i = 0; i <= _max; i++) {
        if (carry) {
            res = 1;
            carry = 0;
        } else {
            res = 0;
        }
        if (s1_size - i - 1 >= 0) {
            a = (int)(s1[s1_size - i - 1] - 48);
        } else {
            a = 0;
        }
        if (s2_size - i - 1 >= 0) {
            b = (int)(s2[s2_size - i - 1] - 48);
        } else {
            b = 0;
        }
        res += (a + b);
        if (res >= 10) {
            if (i == _max) {
            } else {
                res = res % 10;
                carry = 1;
            }
        }
        st.push(res);
    }
    while(st.size() > 0){
        cout << st.top();
        st.pop();
    }
    return 0;
}