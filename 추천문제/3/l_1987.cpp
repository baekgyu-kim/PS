#include <bits/stdc++.h>
using namespace std;
int N, M = 0;
char a[21][21] = {0};
int _max = INT_MIN;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void debug() {
    cout << "\n=================\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void dfs(int y, int x, vector<int> alphabet, int cnt) {
    vector<int> temp;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= M) {
            continue;
        }
        int next_aplhabet_to_int = (int)a[ny][nx] - 65;
        if (alphabet[next_aplhabet_to_int] == 1) {
            continue;
        }
        alphabet[next_aplhabet_to_int] = 1;
        dfs(ny, nx, alphabet, cnt + 1);
        alphabet[next_aplhabet_to_int] = 0;
    }
    _max = max(_max, cnt);
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> alphabet;
    for (int i = 0; i < 26; i++) {
        alphabet.push_back(0);
    }
    alphabet[(int)a[0][0] - 65] = 1;
    dfs(0, 0, alphabet, 1);
    cout << _max;
    return 0;
}