#include <bits/stdc++.h>

using namespace std;

int res = 0;
int N;

bool cmp(int a, int b) { return a > b; }

int solution(vector<int> v) {
    N = v.size();
    int answer = 0;
    sort(v.begin(), v.end(), cmp);
    if (v[0] == 0) {
        return 0;
    }
    for (int i = 0; i < N; i++) {
        if (v[i] > i) {
            res++;
        } else {
            break;
        }
    }
    return res;
}