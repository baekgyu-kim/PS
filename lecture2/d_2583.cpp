// 영역 구하기

#include <bits/stdc++.h>
using namespace std;

int M, N, K = 0;
int a[100][100] = {0};
int visited[100][100] = {0};

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

vector<int> result;

int dfs(int y, int x) {
    int s = 1;
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= M || nx < 0 || nx >= N) {
            continue;
        }
        if (a[ny][nx] == 1 || visited[ny][nx] == 1) {
            continue;
        }
        s += dfs(ny, nx);
    }
    return s;
}

int main() {
    cin >> M >> N >> K;
    int temp = 0;
    int x_left = 0;
    int x_right = 0;
    int y_top = 0;
    int y_bottom = 0;
    for (int i = 0; i < K; i++) {
        cin >> x_left >> y_bottom >> x_right >> y_top;
        for (int x = x_left; x < x_right; x++) {
            for (int y = y_bottom; y < y_top; y++) {
                a[y][x] = 1;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (a[i][j] == 0 && visited[i][j] == 0) {
                result.push_back(dfs(i, j));
            }
        }
    }
    sort(result.begin(), result.end());
    cout << result.size() << "\n";
    for (int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}