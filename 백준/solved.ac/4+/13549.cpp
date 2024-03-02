#include <bits/stdc++.h>
using namespace std;
int N, K = 0;
int visited[200004];
queue<int> q;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    memset(visited, -1, sizeof(visited));
    q.push(N);
    visited[N] = 1;
    while (q.size() > 0) {
        int n = q.front();
        q.pop();
        if(n == K){
            cout << visited[K] - 1;
            return 0;
        }
        if (n > 0 && n * 2 <= 200000 && visited[n * 2] == -1) {
            visited[n * 2] = visited[n];
            q.push(n * 2);
        }
        if (n - 1 >= 0 && visited[n - 1] == -1) {
            visited[n - 1] = visited[n] + 1;
            q.push(n - 1);
        }
        if (n + 1 <= K && visited[n + 1] == -1) {
            visited[n + 1] = visited[n] + 1;
            q.push(n + 1);
        }
    }
}