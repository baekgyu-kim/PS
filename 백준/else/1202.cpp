#include <bits/stdc++.h>
using namespace std;
long long N, K = 0;
// 무게, 가격
vector<pair<long long, long long>> jewelry;
vector<long long> bag;
long long res = 0;
priority_queue<long long> pq;

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    int m, v, c = 0;
    for (int i = 0; i < N; i++) {
        cin >> m >> v;
        jewelry.push_back({m, v});
    }
    for (int i = 0; i < K; i++) {
        cin >> c;
        bag.push_back(c);
    }
}

int main() {
    input();
    sort(bag.begin(), bag.end());
    sort(jewelry.begin(), jewelry.end());
    int jewelry_index = 0;
    for (int i = 0; i < K; i++) {
        while (jewelry_index < N && jewelry[jewelry_index].first <= bag[i]) {
            pq.push(jewelry[jewelry_index++].second);
        }
        if (pq.size() > 0) {
            res += pq.top();
            pq.pop();
        }
    }
    cout << res;
    return 0;
}