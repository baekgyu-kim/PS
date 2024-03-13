#include <bits/stdc++.h>
using namespace std;
int N, K = 0;
int a[51];
int _max = INT_MIN;

int char_to_int(char a) { return (int)(a - 97); }

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (char c : s) {
            a[i] |= (1 << char_to_int(c));
        }
    }
}

int match(int mask) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int n = a[i];
        if ((n & mask) == n) {
            cnt++;
        }
    }
    return cnt;
}

int solve(int alphabet_seq, int k, int alphabet) {
    if (k < 0) {
        return 0;
    }
    if (alphabet_seq == 26) {
        return match(alphabet);
    }
    int include_ith_alphabet = solve(alphabet_seq + 1, k - 1, alphabet | (1 << alphabet_seq));
    if (alphabet_seq != char_to_int('a') && alphabet_seq != char_to_int('n') &&
        alphabet_seq != char_to_int('t') && alphabet_seq != char_to_int('i') &&
        alphabet_seq != char_to_int('c')) {
        int not_include_ith_alphabet = solve(alphabet_seq + 1, k, alphabet);
        return max(include_ith_alphabet, not_include_ith_alphabet);
    }
    return include_ith_alphabet;
}

int main() {
    input();
    if (K < 5) {
        cout << 0;
        return 0;
    }
    cout << solve(0, K, 0);
    return 0;
}