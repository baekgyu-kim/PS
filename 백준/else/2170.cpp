#include <bits/stdc++.h>
using namespace std;

int N = 0;
vector<pair<int, int>> v;
int res = 0;

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    int x, y = 0;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        v.push_back({x, y});
    }
}

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main() {
    input();
    sort(v.begin(), v.end(), cmp);
    int start = v[0].first;
    int end = v[0].second;
    for (int i = 1; i < N; i++){
        if(end < v[i].first){
            res += (end - start);
            start = v[i].first;
            end = v[i].second;
        }else if(v[i].first <= end && v[i].second >= end){
            end = v[i].second;
        }
    }
    res += end - start;
    cout << res;
    return 0;
}