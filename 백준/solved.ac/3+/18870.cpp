#include <bits/stdc++.h>
using namespace std;
int N = 0;
int X[1000004] = {0};
vector<int> y;
int main() {
    cin >> N;
    int x = 0;
    for (int i = 0; i < N; i++) {
        cin >> x;
        X[i] = x;
        y.push_back(x);
    }
    sort(y.begin(), y.end());
    y.erase(unique(y.begin(), y.end()), y.end());

    for (int i = 0; i < N; i++) {
        auto it = lower_bound(y.begin(), y.end(), X[i]);
        if (it == y.end()) {
            cout << "오류";
            return 1;
        }
        cout << it - y.begin() << " ";
    }
    return 0;
}