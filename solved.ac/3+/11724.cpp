#include<bits/stdc++.h>
using namespace std;
int N, M = 0;
vector<int> adj[1004];
int visited[1004] = {0};
int cnt = 0;

void dfs(int u) { 
    visited[u] = 1; 
    if(adj[u].size() == 0){
        return;
    }
    for(int v : adj[u]){
        if(visited[v] == 1){
            continue;
        }
        dfs(v);
    }
    return;
}

int main() {
    cin >> N >> M;
    int u, v = 0;
    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int node = 1; node <= N; node++){
        if(visited[node] == 1){
            continue;
        }else{
            dfs(node);
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}