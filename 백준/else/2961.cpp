#include <bits/stdc++.h>
using namespace std;
int N;
vector<pair<int, int>> v;
int res = INT_MAX;
void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    int S, B;
    for (int i = 0; i < N; i++) {
        cin >> S >> B;
        v.push_back(make_pair(S, B));
    }
}
int main() {
    input();
    int _max = (1 << N);
    for (int i = 1; i < _max; i++) {
        int S = 1;
        int B = 0;
        for (int j = 0; j < N; j++){
            int jth_ingredient = (1 << j);
            if (!(i & jth_ingredient)){
                continue;
            }
            S *= v[j].first;
            B += v[j].second;
        }
        res = min(res, abs(S - B));
    }
    cout << res;
    return 0;
}