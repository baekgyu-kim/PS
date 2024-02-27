#include <bits/stdc++.h>

using namespace std;

int current_hp = 0;
vector<vector<int>> v;
int res = 0;
int visited[8] = {0};

void dfs(int depth, int current_hp) {
    res = max(depth, res);
    for (int i = 0; i < v.size(); i++) {
        if (visited[i] == 1) {
            continue;
        }
        if (v[i][0] > current_hp) {
            continue;
        }
        visited[i] = 1;
        dfs(depth + 1, current_hp - v[i][1]);
        visited[i] = 0;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    current_hp = k;
    v = dungeons;
    dfs(0, current_hp);
    return res;
}