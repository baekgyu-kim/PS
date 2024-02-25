#include <bits/stdc++.h>
using namespace std;
int N, M = 0;
int a[304][304] = {0};
int visited[304][304] = {0};
int dfs_visited[304][304] = {0};
pair<int, int> joonan;
pair<int, int> target;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
queue<pair<int, int>> q;


void dfs(int y, int x, int seq) {
    dfs_visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= M) {
            continue;
        }
        if (visited[ny][nx] > 0) {
            continue;
        }
        if (dfs_visited[ny][nx] > 0) {
            continue;
        }
        if (a[ny][nx] == 0) {
            visited[ny][nx] = seq;
            dfs(ny, nx, seq);
        } else if (a[ny][nx] == 1) {
            q.push(make_pair(y, x));
        }
    }
    return;
}

void jump() {
    while (q.size() > 0) {
        if (visited[target.first][target.second] > 0) {
            return;
        }
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (visited[ny][nx] > 0) {
                continue;
            }
            if (a[ny][nx] == 0) {
                dfs(ny, nx, visited[y][x]);
            }
        }
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (visited[ny][nx] > 0) {
                continue;
            }
            if (a[ny][nx] == 1) {
                visited[ny][nx] = visited[y][x] + 1;
                a[ny][nx] = 0;
                for (int d = 0; d < 304; d++){
                    for (int e = 0; e < 304; e++){
                        dfs_visited[e][d] = 0;
                    }
                }
                    dfs(ny, nx, visited[ny][nx]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    int x, y = 0;
    cin >> y >> x;
    joonan = make_pair(y - 1, x - 1);
    cin >> y >> x;
    target = make_pair(y - 1, x - 1);
    if (joonan.first == target.first && joonan.second == target.second) {
        cout << 0;
        return 0;
    }
    char input;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> input;
            if (input == '0') {
                a[i][j] = 0;
            } else if (input == '1') {
                a[i][j] = 1;
            } else if (input == '*') {
                a[i][j] = 0;
            } else if (input == '#') {
                a[i][j] = 1;
            }
        }
    }
    q.push(joonan);
    visited[joonan.first][joonan.second] = 1;
    jump();
    cout << visited[target.first][target.second] - 1 << "\n";
    return 0;
}