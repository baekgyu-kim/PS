
#include <bits/stdc++.h>
using namespace std;

int N, M = 0;
int a[54][54];
int visited[54][54];
int visited2[54][54];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};
int s = 0;
vector<int> v;
map<int, int> m;
int _max = INT_MIN;
int seq = 1;

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> M >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> a[i][j];
        }
    }
}

void dfs(int y, int x) {
    visited[y][x] = seq;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 1 || nx < 1 || ny > N || nx > M) {
            continue;
        }
        if (a[y][x] & (1 << i)) {
            continue;
        }
        if (visited[ny][nx]) {
            continue;
        }
        s++;
        dfs(ny, nx);
    }
}

int main() {
    input();
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (visited[i][j]) {
                continue;
            }
            s = 1;
            dfs(i, j);
            m[seq] = s;
            seq++;
        }
    }

    cout << m.size() << "\n";
    int ans2 = INT_MIN;
    for (auto p : m) {
        ans2 = max(ans2, p.second);
    }
    cout << ans2 << "\n";

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            visited2[i][j] = 1;
            for (int k = 0; k < 4; k++) {
                int ny = i + dy[k];
                int nx = j + dx[k];
                if (visited2[ny][nx]) {
                    continue;
                }
                if (ny < 1 || nx < 1 || ny > N || nx > M) {
                    continue;
                }
                if ((visited[i][j] != visited[ny][nx]) &&
                    (a[i][j] & (1 << k))) {
                    _max = max(_max, m[visited[i][j]] + m[visited[ny][nx]]);
                }
            }
        }
    }
    cout << _max;
    return 0;
}