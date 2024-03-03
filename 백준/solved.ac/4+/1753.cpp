#include <bits/stdc++.h>
using namespace std;
int INF = 1000000;
int dp[20004];
int V, E, root;
vector<pair<int, int>> a[20004];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    pq;

void input() {
    cin >> V >> E >> root;
    int u, v, weight;
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> weight;
        a[u].push_back({v, weight});
    }
    memset(dp, INF, sizeof(dp));
}

void dijkstra() {
    pq.push({0, root});
    dp[root] = 0;
    while (pq.size() > 0) {
        int u = pq.top().second;
        int weight = pq.top().first;
        pq.pop();
        for(auto p : a[u]){
            int v = p.first;
            int next_weight = weight + p.second;
            if (next_weight < dp[v]) {
                pq.push({next_weight, v});
                dp[v] = next_weight;
            }
        }
    }
}


void output(){
    for (int i = 1; i <= V; i++) {
        if (dp[i] < INF)
            cout << dp[i] << '\n';
        else
            cout << "INF" << '\n';
    }
}

int main() {
    input();
    dijkstra();
    output();
    return 0;
}
