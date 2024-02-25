#include <bits/stdc++.h>
using namespace std;
int K = 0;
vector<char> op;
vector<int> m_num;
vector<int> M_num;
string m_string = "";
string M_string = "";

bool does_num_matches_with_inequality(vector<char> op, vector<int> v) {
    for (int i = 0; i < K; i++) {
        int n1 = v[i];
        int n2 = v[i + 1];
        char opt= op[i];
        if(opt == '<' && n1 >= n2){
            return false;
        }
        if(opt == '>' && n1 <= n2){
            return false;
        }
    }
    return true;
}

string make_string(vector<int> num){
    string res = "";
    for (int n : num) {
        res += to_string(n);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> K;
    char input;
    for (int i = 0; i < K + 1; i++) {
        if (i == K) {
            m_num.push_back(i);
            M_num.push_back(9 - i);
            break;
        }else{
            cin >> input;
            op.push_back(input);
            m_num.push_back(i);
            M_num.push_back(9 - i);
        }

    }
    do {
        if (does_num_matches_with_inequality(op, m_num)) {
            break;
        }
    } while (next_permutation(m_num.begin(), m_num.end()));
    do {
        if (does_num_matches_with_inequality(op, M_num)) {
            break;
        }
    } while (prev_permutation(M_num.begin(), M_num.end()));
    m_string = make_string(m_num);
    M_string = make_string(M_num);
    cout << M_string << "\n" << m_string << "\n";
    return 0;
}