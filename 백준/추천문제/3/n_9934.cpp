#include <bits/stdc++.h>
using namespace std;
int K = 0;
vector<int> v;
vector<int> res[15];

void solve(int first, int last, int depth) {
    if (first == last) {
        res[depth].push_back(v[first]);
        return;
    }
    int mid_index = (first + last) / 2;
    res[depth].push_back(v[mid_index]);
    solve(first, mid_index - 1, depth + 1);
    solve(mid_index + 1, last, depth + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> K;
    int input;
    for (int i = 1; i < (int)(pow(2, K)); i++) {
        cin >> input;
        v.push_back(input);
    }
    solve(0, v.size() - 1, 0);
    int i = 0;
    while(res[i].size() > 0){
        for (int n : res[i]) {
            cout << n << " ";
        }
        cout << "\n";
        i++;
    }

    return 0;
}