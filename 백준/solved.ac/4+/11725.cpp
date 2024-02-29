#include <bits/stdc++.h>
using namespace std;
int N = 0;
vector<int> a[100004];
int parent[100004] = {0};
vector<pair<int, int>> temp;

void dfs(int node) {
    for (int next_node : a[node]) {
        if (parent[next_node] > 0) {
            continue;
        }
        parent[next_node] = node;
        dfs(next_node);
    }
    return;
}

int main() {
    cin >> N;
    int x, y = 0;
    for (int i = 0; i < N - 1; i++) {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    parent[1] = -1;
    dfs(1);
    for (int i = 2; i <= N; i++) {
        cout << parent[i] << "\n";
    }
    return 0;
}