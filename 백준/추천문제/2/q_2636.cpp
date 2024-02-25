// 치즈

#include <bits/stdc++.h>
using namespace std;
int N, M = 0;
int a[104][104] = {0};
int skip_iteration[104][104] = {0};
int visited[104][104] = {0};

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int one = 0;
int steps = 0;

void mark_edge_three() {
    for (int i = 0; i < N; i++) {
        a[i][0] = 3;
        a[i][M - 1] = 3;
    }
    for (int i = 1; i < M - 1; i++) {
        a[0][i] = 3;
        a[N - 1][i] = 3;
    }
}

int step() {
    int step_one = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i][j] == 3) {
                int should_be_put_to_skip_iteration = true;
                if (skip_iteration[i][j] == 1) {
                    continue;
                }
                for (int k = 0; k < 4; k++) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if (ny < 0 || nx < 0 || ny >= N || nx >= M) {
                        continue;
                    }
                    if (a[ny][nx] == 3 || a[ny][nx] == 0) {
                        continue;
                    } else if (a[ny][nx] == 1) {
                        a[ny][nx] = 0;
                        should_be_put_to_skip_iteration = false;
                        step_one++;
                        one--;
                        if (one == 0) {
                            return step_one;
                        }
                    }
                }
                if (should_be_put_to_skip_iteration == true) {
                    skip_iteration[i][j] = 1;
                }
            }
        }
    }
    return 0;
}
void spread_three(int y, int x) {
    a[y][x] = 3;
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= M) {
            continue;
        }
        if (visited[ny][nx] == 1) {
            continue;
        }
        if (a[ny][nx] == 3 || a[ny][nx] == 1) {
            continue;
        } else if (a[ny][nx] == 0) {
            spread_three(ny, nx);
        }
    }
    return;
}

void spread() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i][j] == 3) {
                for (int k = 0; k < 4; k++) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if (ny < 0 || nx < 0 || ny >= N || nx >= M) {
                        continue;
                    }
                    if (a[ny][nx] == 0) {
                        spread_three(ny, nx);
                    }
                }
            }
        }
    }
}


int main() {
    cin >> N >> M;
    int temp = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> temp;
            a[i][j] = temp;
            if (a[i][j] == 1) {
                one++;
            }
        }
    }
    mark_edge_three();
    while (true) {
        steps++;
        spread();
        int step_res = step();
        if (step_res > 0) {
            cout << steps << "\n" << step_res;
            break;
        }
    }
    return 0;
}