#include <bits/stdc++.h>
using namespace std;
int N, M;

int dy[4] = {-1, 0, +1, 0};
int dx[4] = {0, +1, 0, -1};

int a[100][100];
int visited[100][100];

void bfs(int y, int x) {
    queue<pair<int, int> > q;
    visited[y][x] = 1;
    q.push(make_pair(y, x));

    while (q.size() > 0) {
        pair<int, int> u = q.front();
        q.pop();
        int uy = u.first;
        int ux = u.second;

        if (uy == N - 1 && ux == M - 1) {
            return;
        }

        for (int i = 0; i < 4; i++) {
            int ny = uy + dy[i];
            int nx = ux + dx[i];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M) {
                continue;
            }

            if (visited[ny][nx] == 0 && a[ny][nx] == 1) {
                visited[ny][nx] = visited[uy][ux] + 1;
                q.push(make_pair(ny, nx));
            }
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            if (s[j] != ' ') {
                a[i][j] = s[j] - '0';
            }
        }
    }

    bfs(0, 0);


    cout << visited[N - 1][M - 1];
}
