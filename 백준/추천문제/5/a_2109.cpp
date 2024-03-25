#include <bits/stdc++.h>
using namespace std;
int N, res;
// {기간, 돈}
vector<pair<int, int>> v;
struct pq_cmp {
    bool operator()(int a, int b) { return a > b; }
};
priority_queue<int, vector<int>, pq_cmp> pq;

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    int a, b = 0;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        v.push_back({b, a});
    }
}

bool v_cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main() {
    input();
    sort(v.begin(), v.end(), v_cmp);
    for (auto pair : v) {
        pq.push(pair.second);
        if (pq.size() > pair.first) {
            pq.pop();
        }
    }
    while (pq.size()) {
        res += pq.top();
        pq.pop();
    }
    cout << res << "\n";
}