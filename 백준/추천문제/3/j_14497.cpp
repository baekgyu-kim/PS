#include <bits/stdc++.h>
using namespace std;
int N, M = 0;
int a[304][304] = {0};
int visited[304][304] = {0};
pair<int, int> initial;
pair<int, int> target;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
queue<pair<int, int>> q1;
queue<pair<int, int>> q2;
int cnt = 0;

void bfs() {
    while (q1.size() > 0) {
        int y = q1.front().first;
        int x = q1.front().second;
        q1.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= N || nx >= M) {
                continue;
            }
            if (visited[ny][nx] > 0) {
                continue;
            }
            visited[ny][nx] = cnt;
            if (a[ny][nx] == 1) {
                a[ny][nx] = 0;
                q2.push({ny, nx});
            } else {
                q1.push({ny, nx});
            }
        }
    }
}

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    int input_y, input_x = 0;
    cin >> input_y >> input_x;
    initial = {input_y - 1, input_x - 1};
    cin >> input_y >> input_x;
    target = {input_y - 1, input_x - 1};
    char input;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> input;
            if (i == initial.first && j == initial.second) {
                a[i][j] = 0;
                continue;
            }
            if (i == target.first && j == target.second) {
                a[i][j] = 1;
                continue;
            }
            a[i][j] = input - 48;
        }
    }
}
int main() {
    input();
    q1.push(initial);
    visited[initial.first][initial.second] = 1;
    while (a[target.first][target.second] == 1) {
        cnt++;
        while (q2.size() > 0) {
            q2.pop();
        }
        bfs();
        q1 = q2;
    }

    cout << visited[target.first][target.second] << "\n";
    return 0;
}