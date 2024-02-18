#include <bits/stdc++.h>
using namespace std;
int hp[3] = {0};
int N = 0;
int visited[64][64][64];
int attack[6][3] = {{9, 3, 1}, {9, 1, 3}, {3, 1, 9},
                    {3, 9, 1}, {1, 3, 9}, {1, 9, 3}};
struct t {
    int first, second, third;
};

queue<t> q;

void debug() {
    cout << "\n";
    for (int i = 0; i < N; i++) {
        cout << hp[i] << " ";
    }
    cout << "\n";
}

int bfs(int first, int second, int third) {
    visited[first][second][third] = 1;
    q.push({first, second, third});
    while (q.size() > 0) {
        int first = q.front().first;
        int second = q.front().second;
        int third = q.front().third;
        q.pop();
        if (visited[0][0][0]) {
            break;
        }
        for (int i = 0; i < 6; i++) {
            int next_first = max(0, first - attack[i][0]);
            int next_second = max(0, second - attack[i][1]);
            int next_third = max(0, third - attack[i][2]);
            if (visited[next_first][next_second][next_third]) {
                continue;
            }
            visited[next_first][next_second][next_third] =
                visited[first][second][third] + 1;
            q.push({next_first, next_second, next_third});
        }
    }
    return visited[0][0][0] - 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> hp[i];
    }
    int bfs_res = bfs(hp[0], hp[1], hp[2]);
    cout << bfs_res;
    return 0;
}
