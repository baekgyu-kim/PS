#include <bits/stdc++.h>

using namespace std;
vector<int> solution(vector<int> a, vector<vector<int>> commands) {
    vector<int> res;
    vector<int> temp = a;
    for (auto v : commands) {
        vector<int> t;
        int i = v[0] - 1;
        int j = v[1] - 1;
        int k = v[2] - 1;
        for (int p = i; p <= j; p++) {
            t.push_back(a[p]);
        }
        sort(t.begin(), t.end());
        res.push_back(t[k]);
    }

    return res;
}