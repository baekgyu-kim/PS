#include <bits/stdc++.h>
using namespace std;
int N = 0;
int a[504][504] = {0};
int dp[504][504] = {0};

void debug() { 
    for (int i = 0; i < N; i++){
        cout << dp[N - 1][i] << " ";
    }
    return;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> a[i][j];
        }
    }
    dp[0][0] = a[0][0];
    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][j] + a[i][j];
            } else if (j == N - 1) {
                dp[i][j] = dp[i - 1][j - 1] + a[i][j];
            } else {
                int temp = max(dp[i - 1][j - 1], dp[i - 1][j]);
                dp[i][j] = temp + a[i][j];
            }
        }
    }
    cout << *max_element(dp[N - 1], dp[N - 1] + N);
    return 0;
}