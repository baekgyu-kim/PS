#include<bits/stdc++.h>
using namespace std;

int visited[34][34] = {0};
int N, M = 0;
int res = INT_MAX;

bool is_all_x_ok() {
    for (int x = 1; x <= M; x++) {
        int curr = x;
        for (int y = 1; y <= N; y++) {
            if (visited[y][curr])
                curr++;
            else if (visited[y][curr - 1])
                curr--;
        }
        if (curr != x)
            return false;
    }
    return true;
}

void solve(int y, int cnt){
    if(cnt > 3 || cnt >= res){
        return;
    }
    if(is_all_x_ok()){
        res = min(res, cnt);
        return;
    }
    for (int i = y; i <= N; i++){
        for (int j = 1; j < M; j++){
            if(visited[i][j] == 1 || visited[i][j-1] == 1 || visited[i][j+1] == 1){
                continue;
            }
            visited[i][j] = 1;
            solve(i, cnt + 1);
            visited[i][j] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int temp = 0;
    cin >> M >> temp >> N;
    int y, x = 0;
    for (int i = 0; i < temp; i++) {
        cin >> y >> x;
        visited[y][x] = 1;
    }
    solve(1, 0);
    if(res == INT_MAX){
        cout << -1;
    }else{
        cout << res;
    }
    return 0;
}