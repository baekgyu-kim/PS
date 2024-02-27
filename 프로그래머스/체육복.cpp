#include <bits/stdc++.h>

using namespace std;
int N = 0;
int lost[34] = {0};
int reserve[34] = {0};
int lost_n = 0;
int reserve_n = 0;
int res = 0;

void delete_duplicate() {
    for (int i = 1; i <= N; i++) {
        if (lost[i] == 1 && reserve[i] == 1) {
            lost[i] = 0;
            reserve[i] = 0;
            lost_n--;
            reserve_n--;
        }
    }
}

void solve() {
    for (int i = 1; i <= N; i++) {
        if (reserve[i] == 1) {
            if (lost[i - 1] == 1) {
                reserve[i] = 0;
                lost[i - 1] = 0;
                reserve_n--;
                lost_n--;
                continue;
            }
            if (lost[i + 1] == 1) {
                reserve[i] = 0;
                lost[i + 1] = 0;
                reserve_n--;
                lost_n--;
                continue;
            }
        }
    }
}

int solution(int n, vector<int> lost_v, vector<int> reserve_v) {
    N = n;
    lost_n = lost_v.size();
    reserve_n = reserve_v.size();
    for (int l : lost_v) {
        lost[l] = 1;
    }
    for (int r : reserve_v) {
        reserve[r] = 1;
    }
    delete_duplicate();
    solve();
    return n - lost_n;
}