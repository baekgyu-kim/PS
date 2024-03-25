#include <bits/stdc++.h>
using namespace std;

int N = 0;
float a[10000004];
struct cmp {
    bool operator()(float a, float b) { return a > b; }
};
priority_queue<float, vector<float>, cmp> pq;



void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    float f;
    for (int i = 0; i < N; i++) {
        cin >> f;
        pq.push(f);
    }
}

int main() {
    input();
    for (int i = 0; i < 7; i++) {
        cout << fixed << setprecision(3) << pq.top() << "\n";
        pq.pop();
    }

    return 0;
}