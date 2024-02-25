#include <bits/stdc++.h>
using namespace std;
int N, K = 0;
int visited[2][500004];
queue<int> q;
int seq = 0;
bool solved;

bool is_in_range(int n) { return (n <= 0 && n <= 500000); }

bool should_be_continued(int next){
    return (next < 0 || next > 500000 || visited[seq % 2][next]);
}

void bfs() {
    while (q.size()) {
        K += seq;
        if (K > 500000){
            break;
        }
        if (visited[seq % 2][K]) {
            solved = true;
            break;
        }
        int q_size = q.size();
        for (int i = 0; i < q_size; i++) {
            int n = q.front();
            q.pop();
            for (int next : {n + 1, n - 1, n * 2}) {
                if (should_be_continued(next)){
                    continue;
                }
                visited[seq % 2][next] = visited[(seq + 1) % 2][n] + 1;
                if (next == K) {
                    solved = 1;
                    break;
                }
                q.push(next);
            }
            if (solved){
                break;
            }
        }
        if (solved){
            break;
        }
        seq++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    if (N == K) {
        cout << 0;
        return 0;
    }
    q.push(N);
    visited[0][N] = 1;
    seq = 1;
    bfs();
    if(solved){
        cout << seq;
    }else{
        cout << -1;
    }
}
