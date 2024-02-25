// 유기농 배추

#include <bits/stdc++.h>
using namespace std;

int T = 0;
int M = 0; // x 범위
int N = 0; // y 범위
int K = 0;


int a[50][50] = {0};
int visited[50][50] = {0};

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny > N-1 || nx < 0 || nx > M-1){
            continue;
        }
        if(a[ny][nx] == 1 && visited[ny][nx] == 0){
            dfs(ny, nx);
        }
    }
}

int main() {
    cin >> T;
    int result[T];
    for (int t = 0; t < T; t++){
        fill(&a[0][0], &a[0][0] + 50 * 50, 0);
        fill(&visited[0][0], &visited[0][0] + 50 * 50, 0);
        cin >> M >> N >> K;
        int x = 0;
        int y = 0;
        for (int i = 0; i < K; i++) {
            cin >> x >> y;
            a[y][x] = 1;
        }
        int count = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if(a[i][j] == 1 && visited[i][j] == 0){
                    count++;
                    dfs(i, j);
                }
            }
        }
        result[t] = count;
    }
    for (int t = 0; t < T; t++){
        cout << result[t] << "\n";
    }
}