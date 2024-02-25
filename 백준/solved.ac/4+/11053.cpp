#include <bits/stdc++.h>
using namespace std;
int N = 0;
int a[1004] = {0};
int dp[1004] = {0};

int main() {
    cin >> N;
    int temp = 0;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    int res = 0;
    for (int i = 1; i <= N; i++) {
        dp[i] = 1;
        for (int j = i - 1; j > 0; j--) {
            if (a[j] < a[i]) {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
        res = max(dp[i], res);
    }
    cout << res;
    return 0;
}