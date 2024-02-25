#include <bits/stdc++.h>
using namespace std;
int N, K = 0;
queue<int> q;
//{ bfs depth, from }
int visited[1000004][2] = {0};

bool is_in_range(int n) { return (0 <= n && n <= 100000); }

void bfs() {
    while (q.size() > 0) {
        int n = q.front();
        q.pop();
        int next = n - 1;
        if (is_in_range(next)){
            if(visited[next][0] == 0){
                q.push(next);
                visited[next][0] = visited[n][0] + 1;
                visited[next][1] = n;
            }
        }
        next = n + 1;
        if (is_in_range(next)) {
            if (visited[next][0] == 0) {
                q.push(next);
                visited[next][0] = visited[n][0] + 1;
                visited[next][1] = n;
            }
        }
        next = n * 2;
        if (is_in_range(next)) {
            if (visited[next][0] == 0) {
                q.push(next);
                visited[next][0] = visited[n][0] + 1;
                visited[next][1] = n;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    q.push(N);
    visited[N][0] = 1;
    visited[N][1] = -1;
    bfs();
    cout << visited[K][0] - 1 << "\n";
    vector<int> res;
    res.push_back(K);
    int n = K;
    while (visited[n][1] != -1) {
        res.push_back(visited[n][1]);
        n = visited[n][1];
    }
    reverse(res.begin(), res.end());
    for (int n : res) {
        cout << n << " ";
    }
    return 0;
}