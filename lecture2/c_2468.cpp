// 안전 영역

#include <bits/stdc++.h>
using namespace std;

int N = 0;
int a[100][100] = {0};
int a_copy[100][100] = {0};
int visited[100][100] = {0};

int result = 1;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny > N - 1 || nx < 0 || nx > N - 1) {
            continue;
        }
        if (a_copy[ny][nx] == 1 && visited[ny][nx] == 0) {
            dfs(ny, nx);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    int temp = 0;
    int min = 100;
    int max = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> temp;
            if (temp < min) {
                min = temp;
            }
            if (temp > max) {
                max = temp;
            }
            a[i][j] = temp;
        }
    }

    for (int rain = min; rain <= max; rain++) {
        copy(&a[0][0], &a[0][0] + 100 * 100, &a_copy[0][0]);
        fill(&visited[0][0], &visited[0][0] + 100 * 100, 0);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (a_copy[i][j] <= rain) {
                    a_copy[i][j] = 0;
                } else {
                    a_copy[i][j] = 1;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visited[i][j] == 0 && a_copy[i][j] == 1) {
                    count++;
                    dfs(i, j);
                }
            }
        }
        if(result < count){
            result = count;
        }
    }
    cout << result;
    return 0;
}