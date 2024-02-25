#include <bits/stdc++.h>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int visited[504][504] = {0};
int res[504];
int N, M = 0;
int a[504][504] = {0};
int cnt = 0;
set<int> x_set;
queue<pair<int, int>> q;

void bfs() {
    while (q.size() > 0) {
        int y = q.front().first;
        int x = q.front().second;
        x_set.insert(x);
        cnt++;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= N || nx >= M) {
                continue;
            }
            if (visited[ny][nx] == 1) {
                continue;
            }
            if (a[ny][nx] == 0) {
                continue;
            }
            visited[ny][nx] = 1;
            q.push(make_pair(ny, nx));
        }
    }
    for (int x : x_set) {
        res[x] += cnt;
    }
    cnt = 0;
    x_set.clear();
}

int solution(vector<vector<int>> land) {
    N = land.size();
    M = land[0].size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            a[i][j] = land[i][j];
        }
    }
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (a[y][x] == 0 || visited[y][x] == 1) {
                continue;
            }
            q.push(make_pair(y, x));
            visited[y][x] = 1;
            bfs();
        }
    }
    return *max_element(res, res + 504);
}