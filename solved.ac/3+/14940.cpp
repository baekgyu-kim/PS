#include <bits/stdc++.h>
using namespace std;
int N, M = 0;
int a[1004][1004];
int d[1004][1004];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int goal_y, goal_x = 0;
queue<pair<int, int> > q;

void bfs() {
    while (q.size() > 0) {
        pair<int, int> p = q.front();
        int y = p.first;
        int x = p.second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= N || nx >= M) {
                continue;
            }
            if (a[ny][nx] == 0) {
                continue;
            }
            if (d[ny][nx] > -1) {
                continue;
            }
            q.push(make_pair(ny, nx));
            d[ny][nx] = d[y][x] + 1;
        }
    }
    return;
}

int main() {
    cin >> N >> M;
    int temp = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> temp;
            a[i][j] = temp;
            d[i][j] = -1;
            if(temp == 0){
                d[i][j] = 0;
            }
            if (temp == 2) {
                d[i][j] = 0;
                goal_y = i;
                goal_x = j;
            }
        }
    }
    q.push(make_pair(goal_y, goal_x));
    bfs();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << d[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}