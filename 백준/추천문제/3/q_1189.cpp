#include <bits/stdc++.h>
using namespace std;
int a[5][5] = {0};
int visited[5][5] = {0};
int N, M, K = 0;
queue<pair<int, int>> q;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int res = 0;

void dfs(int y, int x, int cnt) {
    if(y == 0 && x == M-1){
        if(cnt == K){
            res++;
        }
        return;
    }
    for (int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= M){
            continue;
        }
        if(visited[ny][nx] == 1){
            continue;
        }
        if(a[ny][nx] == 0){
            continue;
        }
        visited[y][x] = 1;
        dfs(ny, nx, cnt + 1);
        visited[y][x] = 0;
    }
}

int main() {
    cin >> N >> M >> K;
    char input;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> input;
            if (input == '.') {
                a[y][x] = 1;
            }
            if (input == 'T') {
                a[y][x] = 0;
            }
        }
    }
    q.push({N - 1, 0});
    visited[N - 1][0] = 1;
    dfs(N - 1, 0, 1);
    cout << res;
    return 0;
}