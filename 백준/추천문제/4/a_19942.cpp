#include <bits/stdc++.h>
using namespace std;
int N = 0;
int m0, m1, m2, m3 = 0;
vector<vector<int>> a(20, vector<int>(5));
struct T {
    int cost;
    vector<int> v;
};
typedef struct T T;

struct cmp {
    bool operator()(T &A, T &B) {
        if (A.cost == B.cost) {
            string a_str, b_str;
            for (int i : A.v) {
                a_str += (char)(48 + i);
            }
            for (int i : B.v) {
                b_str += (char)(48 + i);
            }
            return a_str > b_str;
        }
        return A.cost > B.cost;
    }
};

priority_queue<T, vector<T>, cmp> pq;
void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    cin >> m0 >> m1 >> m2 >> m3;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> a[i][j];
        }
    }
}

bool meets_requirement(int zero, int one, int two, int three) {
    return (zero >= m0 && one >= m1 && two >= m2 && three >= m3);
}

int main() {
    input();
    for (int used = 1; used < (1 << (N+1)); used++) {
        int zero = 0;
        int one = 0;
        int two = 0;
        int three = 0;
        int cost = 0;
        vector<int> v;
        for (int idx = 1; idx <= N; idx++) {
            if (used & (1 << idx)) {
                zero += a[idx][0];
                one += a[idx][1];
                two += a[idx][2];
                three += a[idx][3];
                cost += a[idx][4];
                v.push_back(idx);
            }
        }
        if (meets_requirement(zero, one, two, three)) {
            T t;
            t.cost = cost;
            t.v = v;
            pq.push(t);
        }
    }
    if (pq.empty() == true) {
        cout << -1;

    } else {
        T res = pq.top();
        int cost = res.cost;
        auto index = res.v;
        cout << cost << "\n";
        for (int i : index) {
            cout << i << " ";
        }
    }
    return 0;
}