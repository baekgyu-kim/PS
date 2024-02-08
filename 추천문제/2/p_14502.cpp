// 연구소

#include <bits/stdc++.h>
using namespace std;

int N, M = 0;
int a[8][8] = {0};
int visited[8][8] = {0};

vector<pair<int, int> > zero;
vector<pair<int, int> > two;

vector<int> areas;

int dy[4] = {-1, 0, +1, 0};
int dx[4] = {0, +1, 0, -1};

void dfs(int y, int x) {
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M) {
            continue;
        }
        if (visited[ny][nx] == 1 || a[ny][nx] == 1) {
            continue;
        }
        visited[ny][nx] = 1;
        dfs(ny, nx);
    }
    return;
}

void build_wall(int i, int j, int k) {
    a[zero[i].first][zero[i].second] = 1;
    a[zero[j].first][zero[j].second] = 1;
    a[zero[k].first][zero[k].second] = 1;
}

void destroy_wall(int i, int j, int k) {
    a[zero[i].first][zero[i].second] = 0;
    a[zero[j].first][zero[j].second] = 0;
    a[zero[k].first][zero[k].second] = 0;
}

void spread_virus(){
    for (auto virus : two) {
        visited[virus.first][virus.second] = 1;
        dfs(virus.first, virus.second);
    }
}

void calculate_area() { 
    fill(&visited[0][0], &visited[0][0] + 8 * 8, 0);
    spread_virus();
    int area = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if(a[i][j] == 0 && visited[i][j] == 0){
                area++;
            }
        }
    }
    areas.push_back(area);
}

int main() {
    cin >> N >> M;
    int temp = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> temp;
            a[i][j] = temp;
            if (temp == 2) {
                two.push_back(make_pair(i, j));
            }
            if (temp == 0) {
                zero.push_back(make_pair(i, j));
            }
        }
    }
    for (int i = 0; i < zero.size() - 2; i++) {
        for (int j = i + 1; j < zero.size() - 1; j++) {
            for (int k = j + 1; k < zero.size(); k++) {
                build_wall(i, j, k);
                calculate_area();
                destroy_wall(i, j, k);
            }
        }
    }
    int max = *max_element(areas.begin(), areas.end());
    cout << max;
}