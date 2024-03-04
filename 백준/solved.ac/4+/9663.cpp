#include <bits/stdc++.h>
using namespace std;
int N = 0;
int a[15] = {0};
int res = 0;

bool is_ok(int x) {
    for (int i = 0; i < x; i++) {
        if (a[i] == a[x]) {
            return false;
        }
        if (abs(a[x] - a[i]) == x - i) {
            return false;
        }
    }
    return true;
}

void solve(int x) {
    if (x == N) {
        res++;
        return;
    }
    for (int i = 0; i < N; i++) {
        a[x] = i;
        if (is_ok(x)) {
            solve(x + 1);
        }
    }
}

int main() {
    cin >> N;
    solve(0);
    cout << res;
    return 0;
}