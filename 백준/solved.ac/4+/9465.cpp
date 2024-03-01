#include <bits/stdc++.h>
using namespace std;
int T, N = 0;
int a[2][100004] = {0};
int dp[2][100004] = {0};
vector<int> res;

void input() {
    cin >> N;
    int input = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }
}

void output() { 
    int _max = 0;
    _max = max(_max, *max_element(dp[0], dp[0] + N));
    _max = max(_max, *max_element(dp[1], dp[1] + N));
    res.push_back(_max);
}

void debug() {
    cout << "\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < N; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void solve() {
    input();
    if(N == 1){
        res.push_back(max(a[0][0], a[1][0]));
        return;
    }
    if(N==2){
        res.push_back(max((a[0][0] + a[1][1]), (a[1][0] + a[0][1])));
        return;
    }
    dp[0][0] = a[0][0];
    dp[1][0] = a[1][0];
    dp[0][1] = a[1][0] + a[0][1];
    dp[1][1] = a[0][0] + a[1][1];
    for (int i = 2; i < N; i++) {
        dp[0][i] = max(dp[1][i - 1] + a[0][i], dp[1][i - 2] + a[0][i]);
        dp[1][i] = max(dp[0][i - 1] + a[1][i], dp[0][i - 2] + a[1][i]);
    }
    // debug();
    output();
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    for (int i = 0; i < T; i++) {
        memset(a, 0, sizeof(a));
        memset(dp, 0, sizeof(dp));
        solve();
    }
    // cout << "\n";
    for (int n : res) {
        cout << n << "\n";
    }
    return 0;
}