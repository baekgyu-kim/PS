#include <bits/stdc++.h>
using namespace std;
int T = 0;
int dp[10004] = {0};

void solve() {
    dp[0] = 1;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 10000; j++) {
            if (i <= j) {
                dp[j] += dp[j - i];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    solve();
    int input = 0;
    for (int i = 0; i < T; i++) {
        cin >> input;
        cout << dp[input] << "\n";
    }
    return 0;
}