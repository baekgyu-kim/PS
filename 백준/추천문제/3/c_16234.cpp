#include <bits/stdc++.h>
using namespace std;
int N, L, R = 0;
int a[52][52] = {0};
int visited[52][52] = {0};
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int cnt = 0;
vector<pair<int, int> > dfs_v;
int sum = 0;

bool is_difference_between_L_and_R(int a, int b) {
    int diff = a - b;
    if (diff < 0) {
        diff = -diff;
    }
    if (L <= diff && diff <= R) {
        return true;
    } else {
        return false;
    }
}

void debug() {
    cout << "\n\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";
}

void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= N || nx >= N){
            continue;
        }
        if(visited[ny][nx] == 1){
            continue;
        }
        if (is_difference_between_L_and_R(a[y][x], a[ny][nx])){
            dfs_v.push_back(make_pair(ny, nx));
            sum += a[ny][nx];
            dfs(ny, nx);
        }
    }
}

int main() {
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }
    while (1) {
        int flag = 0;
        memset(visited, 0, sizeof(visited));
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (visited[y][x] == 1) {
                    continue;
                }
                dfs_v.clear();
                dfs_v.push_back(make_pair(y, x));
                sum = a[y][x];
                dfs(y, x);
                if (dfs_v.size() > 1) {
                    for (auto p : dfs_v) {
                        int avg = sum / dfs_v.size();
                        a[p.first][p.second] = avg;
                        flag++;
                    }
                }
            }
        }
        if (flag == 0) {
            break;
        }
        cnt++;
    }

    cout << cnt;
    return 0;
}