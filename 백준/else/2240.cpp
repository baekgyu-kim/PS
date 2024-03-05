#include <bits/stdc++.h>
using namespace std;
int dp[1004][2][34];
int fruit[1004];
int total_fruit_num, max_move;
int answer = 0;

int solve(int fruit_index, int tree, int move_cnt) {
    if (move_cnt < 0) {
        return INT_MIN;
    }
    if (fruit_index == total_fruit_num) {
        if (move_cnt == 0) {
            return 0;
        } else {
            return INT_MIN;
        }
    }
    int &res = dp[fruit_index][tree][move_cnt];
    if (res != -1) {
        return res;
    }
    if (tree == 1) {
        res = max(solve(fruit_index + 1, 0, move_cnt - 1),
                      solve(fruit_index + 1, 1, move_cnt)) +
                  (tree == fruit[fruit_index] - 1);
        return res;
    } else {
        res = max(solve(fruit_index + 1, 1, move_cnt - 1),
                      solve(fruit_index + 1, 0, move_cnt)) +
                  (tree == fruit[fruit_index] - 1);
        return res;
    }
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> total_fruit_num >> max_move;
    for (int i = 0; i < total_fruit_num; i++) {
        cin >> fruit[i];
    }
    answer = max(solve(0, 1, max_move - 1), solve(0, 0, max_move));
    cout << answer;
    return 0;
}
