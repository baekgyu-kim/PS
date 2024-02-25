#include <bits/stdc++.h>
using namespace std;
int N, M = 0;
int a[54][54] = {0};
int b[54][54] = {0};
int visited[54][54] = {0};
queue<pair<int, int> > q;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int _max = 0;

pair<int, pair<int, int> > bfs() {
    int res, res_y, res_x = 0;
    while (q.size() > 0) {
        int y = q.front().first;
        int x = q.front().second;
        visited[y][x] = 1;
        q.pop();
        for (int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(visited[ny][nx] == 1){
                continue;
            }
            if(ny < 0 || nx < 0 || ny >= N || nx >= M){
                continue;
            }
            if(b[ny][nx] == 0){
                continue;
            }
            if(b[ny][nx] == 1){
                q.push(make_pair(ny, nx));
                b[ny][nx] = b[y][x] + 1;
                if(res <= b[ny][nx]){
                    res = b[ny][nx];
                    res_y = ny;
                    res_x = nx;
                }
            }
        }
    }
    return make_pair(res, make_pair(res_y, res_x));
}

int main() {
    cin >> N >> M;
    string input = "";
    for (int i = 0; i < N; i++) {
        cin >> input;
        for (int j = 0; j < M; j++) {
            if (input[j] == 'L') {
                a[i][j] = 1;
            } else {
                a[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i][j] == 1) {
                memset(visited, 0, sizeof(visited));
                memcpy(b, a, sizeof(a));
                q.push(make_pair(i, j));
                auto bfs_res = bfs();
                _max = max(_max, bfs_res.first);
            }
        }
    }
    cout << _max - 1;
    return 0;
}