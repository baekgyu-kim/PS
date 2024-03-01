#include <bits/stdc++.h>
using namespace std;
int N, M = 0;
int a[1030][1030] = {0};
int s[1030][1030] = {0};
vector<pair<pair<int, int>, pair<int, int>>> q;
vector<int> res;

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> a[i][j];
        }
    }
    int x1, y1, x2, y2 = 0;
    for (int i = 1; i <= M; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        q.push_back({{x1, y1}, {x2, y2}});
    }
}

void debug() {
    cout << "\n";
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            cout << s[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void calculate_sum() {
    s[1][1] = a[1][1];
    for (int i = 2; i <= N; i++) {
        s[1][i] = s[1][i - 1] + a[1][i];
        s[i][1] = s[i - 1][1] + a[i][1];
    }
    for (int i = 2; i <= N; i++) {
        for (int j = 2; j <= N; j++) {
            s[i][j] = a[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }
}

void calculate_res(int seq) {
    auto c1 = q[seq].first;
    auto c2 = q[seq].second;
    int little_y = c1.first;
    int little_x = c1.second;
    int large_y = c2.first;
    int large_x = c2.second;
    int ans = 0;
    if (little_y == large_y && little_x == large_x) {
        ans = a[little_y][little_x];
        res.push_back(ans);
        return;
    }

    ans = s[large_y][large_x];
    int delete_y_left = large_y;
    int delete_x_left = little_x - 1;
    int delete_y_top = little_y - 1;
    int delete_x_top = large_x;
    ans -= s[delete_y_left][delete_x_left];
    ans -= s[delete_y_top][delete_x_top];
    ans += s[little_y - 1][little_x - 1];
    res.push_back(ans);
}

int main() {
    input();
    calculate_sum();
    for (int i = 0; i < M; i++) {
        calculate_res(i);
    }
    for (int n : res) {
        cout << n << "\n";
    }
    return 0;
}