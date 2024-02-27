#include <bits/stdc++.h>

using namespace std;

set<int> res;
string a = "";
int N = 0;

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void permutation(vector<int> v) {
    string temp = "";
    for (int i = 0; i < v.size(); i++) {
        temp += a[v[i]];
    }
    do {
        int n = stoi(temp);
        cout << n << "\n";
        if (is_prime(n)) {
            res.insert(n);
        }
    } while (next_permutation(temp.begin(), temp.end()));
}

void combination(int r, int start, vector<int> v) {
    if (v.size() == r) {
        permutation(v);
    }
    for (int i = start + 1; i < N; i++) {
        v.push_back(i);
        combination(r, i, v);
        v.pop_back();
    }
}

int solution(string numbers) {
    a = numbers;
    N = numbers.size();
    sort(a.begin(), a.end());
    for (int r = 1; r <= N; r++) {
        vector<int> v;
        combination(r, -1, v);
    }
    return res.size();
}