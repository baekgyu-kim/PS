#include <bits/stdc++.h>
using namespace std;

int N, M = 0;
char a[24][24] = {0};
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int _max = INT_MIN;

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }
}

int capital_to_int(char A) { return (int)(A - 65); }

void dfs(int y, int x, int used, int cnt) {
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= M) {
            continue;
        }
        int next_alphabet = capital_to_int(a[ny][nx]);
        if (used & (1 << next_alphabet)) {
            continue;
        }
        used |= (1 << next_alphabet);
        dfs(ny, nx, used, cnt + 1);
        used &= ~(1 << next_alphabet);
    }
    _max = max(_max, cnt);
}

int main() {
    input();
    int used = (1 << capital_to_int(a[0][0]));
    dfs(0, 0, used, 1);
    cout << _max;
    return 0;
}