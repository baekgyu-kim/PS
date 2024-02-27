#include <bits/stdc++.h>

using namespace std;
int N = 0;
int res = 0;
vector<int> v;
int target;

void solve(int idx, int sum) {
    if (idx < N - 1) {
        solve(idx + 1, sum + v[idx]);
        solve(idx + 1, sum - v[idx]);
    } else {
        if (sum + v[idx] == target || sum - v[idx] == target) {
            res++;
            return;
        }
    }
    return;
}

int solution(vector<int> numbers, int n) {
    v = numbers;
    N = numbers.size();
    target = n;
    solve(0, 0);
    return res;
}