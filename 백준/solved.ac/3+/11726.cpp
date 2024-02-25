#include <bits/stdc++.h>
using namespace std;

int N = 0;
int last = 0;
int combination[1000][1000] = {-1};

int n_C_r(int n, int r) {
    if (n == 0 || r == 0 || n == r){
        return 1;
    }
    if(combination[n][r] > 0){
        return combination[n][r] % 10007;
    }
    combination[n][r] =  n_C_r(n - 1, r - 1) % 10007 + n_C_r(n - 1, r) % 10007;
    return combination[n][r] % 10007;
}

int n_H_r(int n, int r) { return n_C_r(n + r - 1, r); }

int cases(int n) {
    int result = 1;
    result += n - 1;
    if (n % 2 == 1) {
        for (int i = 0; i < n / 2 - 1; i++) {
            result += n_H_r(n / 2 + 1 - i, 2 * i + 1) % 10007;
        }
    } else {
        for (int i = 0; i < n / 2 - 1; i++) {
            result += n_H_r(n / 2 + 1 - i, 2 * i) % 10007;
        }
    }

    return result % 10007;
}

int main() {
    cin >> N;
    for (int i = 0; i < 1000; i++) {
        combination[i][i] = 1;
        combination[i][0] = 1;
        combination[0][i] = 1;
    }

    cout << cases(N) % 10007 << " ";

    return 0;
}