#include <bits/stdc++.h>
using namespace std;
int M, N = 0;
int a[1004][1004] = {0};

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

queue<pair<int, int> > q;

void bfs() {
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
            if (a[ny][nx] == 1 || a[ny][nx] == -1) {
                continue;
            }
            if (a[ny][nx] == 0) {
                a[ny][nx] = a[y][x] + 1;
                q.push(make_pair(ny, nx));
            }
        }
    }
    return;
}

int time_spent() {
    int t = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i][j] == 0) {
                return 0;
            }
            if (a[i][j] > t) {
                t = a[i][j];
            }
        }
    }
    return t;
}

int main() {
    int temp = 0;
    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> temp;
            a[i][j] = temp;
            if (temp == 1) {
                q.push(make_pair(i, j));
            }
        }
    }

    bfs();

    int t = time_spent();
    cout << t - 1;
    return 0;
}