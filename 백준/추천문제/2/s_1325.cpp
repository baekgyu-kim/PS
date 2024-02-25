#include <bits/stdc++.h>
using namespace std;
int N, M = 0;
vector<int> adj[10004];
int visited[10004] = {0};
int nodes[10004];

bool cmp(int a, int b) { return a > b; }

int dfs(int u) { 
    visited[u] = 1;
    int res = 1;
    for(int v : adj[u]){
        if(visited[v] == 1){
            continue;
        }
        res += dfs(v);
    }
    return res;
}

int main() {
    cin >> N >> M;
    int to, from = 0;
    for (int i = 0; i < M; i++) {
        cin >> to >> from;
        adj[from].push_back(to);
    }
    for (int node = 1; node <= N; node++){
        memset(visited, 0, sizeof(visited));
        int dfs_res = dfs(node);
        nodes[node] = dfs_res;
        M = max(dfs_res, M);
    }
    int M = *max_element(nodes + 1, nodes+ N + 1);
    for (int node = 1; node <= N; node++) {
        if(M == nodes[node]){
            cout << node << " ";
        }
    }
    return 0;
}