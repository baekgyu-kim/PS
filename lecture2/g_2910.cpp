// 빈도 정렬

#include <bits/stdc++.h>
using namespace std;

int N, C = 0;
map<int, int> m;
map<int, int> m_order;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second == b.second) {
        return m_order[a.first] < m_order[b.first];
    }
    return a.second > b.second;
}

int main() {
    cin >> N >> C;
    int temp = 0;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        if (m.find(temp) == m.end()) {
            m[temp] = 1;
            m_order[temp] = i;
        } else {
            m[temp] = m[temp] + 1;
        }
    }
    vector<pair<int, int> > v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++){
        for (int j = 0; j < v[i].second; j++){
            cout << v[i].first << " ";
        }
    }

        return 0;
}