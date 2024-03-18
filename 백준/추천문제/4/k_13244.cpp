#include <bits/stdc++.h>
using namespace std;
int T = 0;
int node, edge = 0;
vector<int> tree[1004];
int visited[1004] = {0};
vector<bool> res;
int cnt = 0;

void input() {
    memset(tree, 0, sizeof(tree));
    cin >> node >> edge;
    int node1, node2 = 0;
    for (int i = 0; i < edge; i++) {
        cin >> node1 >> node2;
        tree[node1].push_back(node2);
        tree[node2].push_back(node1);
    }
}

void dfs(int parent, int n) {
    visited[n] = 1;
    for (int next_node : tree[n]) {
        if(next_node == parent){
            continue;
        }
        if (visited[next_node]) {
            cnt = INT_MIN;
            return;
        }
        cnt++;
        dfs(n, next_node);
    }
}

bool is_tree() {
    cnt = 1;
    memset(visited, 0, sizeof(visited));
    dfs(0, 1);
    if (cnt == node) {
        return 1;
    } else {
        return 0;
    }
}

void solve() {
    input();
    res.push_back(is_tree());
}
int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        solve();
    }
    for (bool is_tree : res) {
        if (is_tree) {
            cout << "tree\n";
        } else {
            cout << "graph\n";
        }
    }
    return 0;
}