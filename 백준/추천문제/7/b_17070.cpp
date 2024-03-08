#include <bits/stdc++.h>
using namespace std;
int N = 0;
int a[20][20] = {0};
int dp[20][20][3] = {0};
int res = 0;
void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> a[i][j];
        }
    }
}

bool is_ok_to_move(int y, int x, int direction) {
    if (direction == 0 || direction == 2) {
        if (a[y][x] == 0) {
            return true;
        }
    } else if (direction == 1) {
        if (a[y][x] == 0 && a[y - 1][x] == 0 && a[y][x - 1] == 0) {
            return true;
        }
    }
    return false;
}

void solve(){
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (is_ok_to_move(i, j + 1, 0)) {
                dp[i][j + 1][0] += dp[i][j][0];
            }
            if (is_ok_to_move(i + 1, j + 1, 1))
                dp[i + 1][j + 1][1] += dp[i][j][0];

            if (is_ok_to_move(i + 1, j, 2))
                dp[i + 1][j][2] += dp[i][j][2];
            if (is_ok_to_move(i + 1, j + 1, 1))
                dp[i + 1][j + 1][1] += dp[i][j][2];

            if (is_ok_to_move(i, j + 1, 0))
                dp[i][j + 1][0] += dp[i][j][1];
            if (is_ok_to_move(i + 1, j, 2))
                dp[i + 1][j][2] += dp[i][j][1];
            if (is_ok_to_move(i + 1, j + 1, 1))
                dp[i + 1][j + 1][1] += dp[i][j][1];
        }
    }
}

int main() {
    input();
    dp[1][2][0] = 1;
    solve();
    for (int direction = 0; direction < 3; direction++){
        res += dp[N][N][direction];
    }
    cout << res;
    return 0;
}