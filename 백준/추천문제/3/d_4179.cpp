#include <bits/stdc++.h>
using namespace std;
int N, M = 0;
int a[1004][1004] = {0};
int jihun[1004][1004] = {0};
int fire[1004][1004] = {0};
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
queue<pair<int, int> > fire_q;
queue<pair<int, int> > jihun_q;
int res = 0;

void debug() {
    cout << "\n\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";
}

void fire_bfs(){
    while(fire_q.size() > 0){
        int y = fire_q.front().first;
        int x = fire_q.front().second;
        fire_q.pop();
        for (int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= N || nx >= M){
                continue;
            }
            if(fire[ny][nx] != INT_MAX){
                continue;
            }
            if(a[ny][nx] == 1){
                continue;
            }
            fire[ny][nx] = fire[y][x] + 1;
            fire_q.push(make_pair(ny, nx));
        }
    }
}

bool is_jihun_at_edge(int y, int x){
    if(y == 0 || x == 0 || y == N - 1 || x == M - 1){
        return true;
    }else{
        return false;
    }
}

void jihun_bfs(){
    while(jihun_q.size() > 0){
        int y = jihun_q.front().first;
        int x = jihun_q.front().second;
        jihun_q.pop();
        if(is_jihun_at_edge(y, x)){
            res = jihun[y][x];
            return;
        }
        for (int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= N || nx >= M){
                continue;
            }
            if(jihun[ny][nx] > 0){
                continue;
            }
            if(a[ny][nx] == 1){
                continue;
            }
            int next_jihun = jihun[y][x] + 1;
            if (fire[ny][nx] <= next_jihun) {
                continue;
            }
            jihun[ny][nx] = next_jihun;
            jihun_q.push(make_pair(ny, nx));
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fill(&fire[0][0], &fire[0][0] + 1004 * 1004, INT_MAX);
    cin >> N >> M;
    char input;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> input;
            if (input == '#') {
                a[i][j] = 1;
            } else if (input == '.') {
                a[i][j] = 0;
            } else if (input == 'J') {
                a[i][j] = 0;
                jihun[i][j] = 1;
                jihun_q.push(make_pair(i, j));
            } else if (input == 'F') {
                a[i][j] = 2;
                fire[i][j] = 1;
                fire_q.push(make_pair(i, j));
            }
        }
    }
    fire_bfs();
    jihun_bfs();
    if(res == 0){
        cout << "IMPOSSIBLE";
    }else{
        cout << res;
    }
    return 0;
}