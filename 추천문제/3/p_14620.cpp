#include <bits/stdc++.h>
using namespace std;
int N = 0;
int a[204][204] = {0};
int visited[204][204] = {0};
int sum[204][204];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int res = INT_MAX;

bool is_ok(int y, int x) {
    if (visited[y][x] == 1) {
        return false;
    }
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= N || nx >= N){
            return false;
        }
        if (visited[ny][nx] == 1) {
            return false;
        }
    }
    return true;
}

int add_flower_and_return_price(int y, int x) {
    visited[y][x] = 1;
    int sum = a[y][x];
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        visited[ny][nx] = 1;
        sum += a[ny][nx];
    }
    return sum;
}

void erase_flower(int y, int x) { 
    visited[y][x] = 0;
    for (int i = 0; i < 4; i++){
        visited[y + dy[i]][x + dx[i]] = 0;
    }
}

void solve(int nth_flower, int sum){
    if (nth_flower == 3) {
        res = min(res, sum);
        return;
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if(!is_ok(i, j)){
                continue;
            }
            int nth_price = add_flower_and_return_price(i, j);
            solve(nth_flower + 1, sum + nth_price);
            erase_flower(i, j);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }
    solve(0, 0);
    cout << res;
    return 0;
}