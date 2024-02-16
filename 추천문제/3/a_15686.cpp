#include <bits/stdc++.h>
using namespace std;
int N, M = 0;
vector<pair<int, int> > chickens;
vector<pair<int, int> > houses;
int chicken_dist = 0;
int D = INT_MAX;

int dist(pair<int, int> a, pair<int, int> b) {
    int x_diff = b.first - a.first;
    int y_diff = b.second - a.second;
    if (x_diff < 0) {
        x_diff = -x_diff;
    }
    if (y_diff < 0) {
        y_diff = -y_diff;
    }
    return x_diff + y_diff;
}

int calculate_city_dists(vector<int> survive_chicken_index) {
    int res = 0;
    for (pair<int, int> h : houses) {
        int d = INT_MAX;
        for (int survive : survive_chicken_index) {
            d = min(d, dist(chickens[survive], h));
        }
        res += d;
    }
    return res;
}

void combination(int start, vector<int> v) {
    if (v.size() == M) {
        D = min(D, calculate_city_dists(v));
    }
    for (int i = start + 1; i < chickens.size(); i++) {
        v.push_back(i);
        combination(i, v);
        v.pop_back();
    }
    return;
}

int main() {
    cin >> N;
    cin >> M;
    int a = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> a;
            if (a == 2) {
                chickens.push_back(make_pair(i, j));
            }
            if (a == 1) {
                houses.push_back(make_pair(i, j));
            }
        }
    }
    vector<int> v;
    combination(-1, v);
    cout << D;
    return 0;
}