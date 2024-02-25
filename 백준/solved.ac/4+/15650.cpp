#include <bits/stdc++.h>
using namespace std;
int N, R = 0;

void print_permutation(vector<int> v){
    for (int i : v) {
        cout << i << " ";
    }
    cout << "\n";
}

void combination(int n, int r, int start, vector<int> v){
    if(v.size() == r){
        print_permutation(v);
        return;
    }
    for (int i = start + 1; i <= n; i++){
        v.push_back(i);
        combination(n, r, i, v);
        v.pop_back();
    }
}

int main() {
    cin >> N >> R;
    vector<int> v;
    combination(N, R, 0, v);
    return 0;
}