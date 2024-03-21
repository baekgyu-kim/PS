#include <bits/stdc++.h>
using namespace std;

int N = 0;
int a[30][30];
int visited[30][30];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
vector<int> v;
int cnt = 0;

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    char c;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> c;
            a[i][j] = (int)(c - 48);
        }
    }
}

void dfs(int y, int x) { 
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= N || nx >= N){
            continue;  
        }
        if(visited[ny][nx]){
            continue;  
        }
        if(a[ny][nx] == 0){
            continue;
        }
        cnt++;
        dfs(ny, nx);
    }
}

int main() {
    input();
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if(visited[i][j]){
                continue;
            }
            if(a[i][j] == 0){
                continue;
            }
            cnt = 1;
            dfs(i, j);
            v.push_back(cnt);
        }
    }
    cout << v.size() << "\n";
    sort(v.begin(), v.end());
    for(int n : v){
        cout << n << "\n";
    }
    return 0;
}