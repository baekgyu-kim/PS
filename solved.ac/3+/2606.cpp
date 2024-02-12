#include <bits/stdc++.h>
using namespace std;
int N = 0;
int M = 0;
vector<int> adj[104];
int visited[104] = {0};
int cnt = 0;

void dfs(int node) {
    visited[node] = 1;
    cnt++;
    if(adj[node].size() > 0){
        for (int n : adj[node]) {
            if (visited[n] == 1) {
                continue;
            }
            dfs(n);
        }
    }
    return;
}

int main() {
    cin >> N;
    cin >> M;
    int from, to = 0;
    for (int i = 0; i < M; i++) {
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    dfs(1);
    cout << cnt - 1;
}