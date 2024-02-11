#include <bits/stdc++.h>
using namespace std;
int N, K = 0;
queue < pair < int, int > > q;
int visited[100004] = {0};

int is_ok_to_be_put_into_queue(int n){
    if(0 <= n && n <= 100000 && visited[n] == 0){
        return 1;
    }else{
        return 0;
    }
}

void bfs(int n) {
    while(true){
        if(q.empty() == true){
            return;
        }
        int num = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (num == K) {
            cout << cnt;
            return;
        }
        if(is_ok_to_be_put_into_queue(num - 1) == true){
            visited[num - 1] = 1;
            q.push(make_pair(num - 1, cnt + 1));
        }
        if (is_ok_to_be_put_into_queue(num + 1) == true) {
            visited[num + 1] = 1;
            q.push(make_pair(num + 1, cnt + 1));
        }
        if (is_ok_to_be_put_into_queue(num * 2) == true) {
            visited[num * 2] = 1;
            q.push(make_pair(num * 2, cnt + 1));
        }
    }
}

int main() {
    cin >> N >> K;
    q.push(make_pair(N, 0));
    visited[N] = 1;
    bfs(N);
    return 0;
}