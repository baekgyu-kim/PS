#include <bits/stdc++.h>
using namespace std;
int N = 0;
vector<pair<int, int>> tree[10004];
queue<int> q;
int visited[10004] = {0};
priority_queue<pair<int, int>> pq;
int left, right = 0;
int root = 1;
int new_start = 0;
int _max = INT_MIN;

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    int parent, child, weight = 0;
    for (int i = 0; i < N - 1; i++) {
        cin >> parent >> child >> weight;
        tree[parent].push_back({child, weight});
        tree[child].push_back({parent, weight});
    }
}

bool is_leaf(int node) {
    int cnt = 0;
    for(auto p : tree[node]){
        if(visited[p.first] == 0){
            cnt++;
        }
    }
    if(cnt == 0){
        return true;
    }else{
        return false;
    }
}

void bfs() {
    while (q.size() > 0) {
        int node = q.front();
        q.pop();
        if (is_leaf(node)) {
            pq.push({visited[node], node});
            continue;
        }
        for (auto p : tree[node]) {
            int next_node = p.first;
            int next_weight = p.second;
            if (visited[next_node] > 0) {
                continue;
            }
            q.push(next_node);
            visited[next_node] = visited[node] + next_weight;
        }
    }
}

void res_bfs() {
    while (q.size() > 0) {
        int node = q.front();
        q.pop();
        for (auto p : tree[node]) {
            int next_node = p.first;
            int next_weight = p.second;
            if (visited[next_node] > 0) {
                continue;
            }
            q.push(next_node);
            visited[next_node] = visited[node] + next_weight;
            _max = max(_max, visited[next_node]);
        }
    }
}

int main() {
    input();
    if (N == 1) {
        cout << 0;
        return 0;
    }
    visited[root] = 1;
    for (auto p : tree[root]) {
        q.push(p.first);
        visited[p.first] = visited[root] + p.second;
    }

    bfs();
    new_start = pq.top().second;
    for (int i = 0; i < 10004; i++) {
        visited[i] = 0;
    }
    while(q.size() > 0){
        q.pop();
    }
    visited[new_start] = 1;
    for (auto p : tree[new_start]) {
        q.push(p.first);
        visited[p.first] = visited[new_start] + p.second;
    }
    res_bfs();
    cout << _max - 1;
    return 0;
}