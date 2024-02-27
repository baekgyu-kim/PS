#include <bits/stdc++.h>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int visited[104][104] = {0};
queue<pair<int, int>> q;
int N, M = 0;

void bfs(vector<vector<int>> a) {
    while (q.size() > 0) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= N || nx >= M) {
                continue;
            }
            if (visited[ny][nx] > 0) {
                continue;
            }
            if (a[ny][nx] == 0) {
                continue;
            }
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
    return;
}

int solution(vector<vector<int>> maps) {
    q.push({0, 0});
    visited[0][0] = 1;
    N = maps.size();
    M = maps[0].size();
    bfs(maps);
    int res = visited[N - 1][M - 1];
    if (res == 0) {
        return -1;
    } else {
        return visited[N - 1][M - 1];
    }
}