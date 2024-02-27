#include <bits/stdc++.h>
using namespace std;
map<string, int> m;
int solution(vector<vector<string>> clothes) {
    for (auto v : clothes) {
        string key = v[1];
        if (m.find(key) == m.end()) {
            m[key] = 1;
        } else {
            m[key] += 1;
        }
    }
    int res = 1;
    for (auto p : m) {
        res *= (p.second + 1);
    }
    return res - 1;
}