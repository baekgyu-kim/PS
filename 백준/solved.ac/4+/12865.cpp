#include <bits/stdc++.h>
using namespace std;
int N, K;
vector<pair<int, int>> a;
int dp[104][100004] = {0};

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    int weight, value;
    for (int i = 0; i < N; i++) {
        cin >> weight >> value;
        a.push_back({weight, value});
    }
}

void solve() {
    for (int limit = 1; limit <= K; limit++) {
        for (int item_index = 1; item_index <= N; item_index++) {
            int current_weight = 0;
            auto item = a[item_index - 1];
            auto weight = item.first;
            auto value = item.second;
            if (limit < weight) {
                dp[item_index][limit] = dp[item_index - 1][limit];
            } else {
                dp[item_index][limit] =
                    max(dp[item_index - 1][limit - weight] + value,
                        dp[item_index - 1][limit]);
            }
        }
    }
}

int main() {
    input();
    solve();
    cout << dp[N][K];
    return 0;
}