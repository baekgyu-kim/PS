#include <bits/stdc++.h>
using namespace std;
int N = 0;
int K = 0;
queue<int> q;
int visited[100004] = {0};
int cnt[100004] = {0};
int res = INT_MAX;

bool is_in_range(int n) {
    if (0 <= n && n <= 100000) {
        return true;
    } else {
        return false;
    }
}

void bfs() {
    while (q.size() > 0) {
        int num = q.front();
        q.pop();
        if (is_in_range(num - 1)) {
            if(visited[num - 1] == 0){
                visited[num - 1] = visited[num] + 1;
                cnt[num - 1] += cnt[num];
                q.push(num - 1);
            }else if(visited[num - 1] == visited[num] + 1){
                cnt[num - 1] += cnt[num];
            }
        }
        if (is_in_range(num + 1)) {
            if(visited[num + 1] == 0){
                visited[num + 1] = visited[num] + 1;
                cnt[num + 1] += cnt[num];
                q.push(num + 1);
            } else if (visited[num + 1] == visited[num] + 1) {
                cnt[num + 1] += cnt[num];
            }
        }
        if (is_in_range(num * 2)) {
            if(visited[num * 2] == 0){
                visited[num * 2] = visited[num] + 1;
                cnt[num * 2] += cnt[num];
                q.push(num * 2);
            } else if (visited[num * 2] == visited[num] + 1) {
                cnt[num * 2] += cnt[num];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    if(N == K){
        cout << 0 << "\n" << 1;
        return 0;
    }
    q.push(N);
    visited[N] = 1;
    cnt[N] = 1;
    bfs();
    cout << visited[K] - 1 << "\n" << cnt[K];
    return 0;
}