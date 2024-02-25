#include <bits/stdc++.h>
using namespace std;
int N, R = 0;
vector<int> input;
vector<vector<int>> res;

void add_to_v(vector<int> v) {
    do {
        vector<int> res_temp;
        for (int i : v) {
            res_temp.push_back(input[i]);
        }
        res.push_back(res_temp);
    } while (next_permutation(v.begin(), v.end()));
}

void combination(int N, int R, int start, vector<int> v) {
    if (v.size() == R) {
        add_to_v(v);
        return;
    }
    for (int i = start + 1; i < N; i++) {
        v.push_back(i);
        combination(N, R, i, v);
        v.pop_back();
    }
}

bool cmp(vector<int> a, vector<int> b) {
    int len = a.size();
    for (int i = 0; i < len; i++) {
        if(a[i] == b[i]){
            continue;
        }
        return a[i] < b[i];
    }
}

int main() {
    cin >> N >> R;
    int temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        input.push_back(temp);
    }
    vector<int> v;
    combination(N, R, -1, v);
    sort(res.begin(), res.end(), cmp);
    for(auto res_v : res){
        for(auto n : res_v){
            cout << n << " ";
        }
        cout << "\n";
    }
}