#include <bits/stdc++.h>
using namespace std;
int N = 0;
pair<int, int> tree[30];
int visited[30] = {0};
vector<int> pre_v;
vector<int> in_v;
vector<int> post_v;

void debug() {
    cout << "\n";
    for (int i = 0; i < N; i++) {
        auto p = tree[i];
        cout << i << " : ";
        cout << p.first << " " << p.second << "\n";
    }
}

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    char input1, input2, input3;
    for (int i = 0; i < N; i++) {
        cin >> input1 >> input2 >> input3;
        int left, right = 0;
        if (input2 == '.') {
            left = -1;
        } else {
            left = input2 - 65;
        }
        if (input3 == '.') {
            right = -1;
        } else {
            right = input3 - 65;
        }
        tree[input1 - 65] = {left, right};
    }
}

void pre_order(int root) {
    int left = tree[root].first;
    int right = tree[root].second;
    pre_v.push_back(root);
    if (left == -1 && right == -1) {
        return;
    }
    if (left > -1) {
        pre_order(left);
    }
    if (right > -1) {
        pre_order(right);
    }
}
void in_order(int root) {
    int left = tree[root].first;
    int right = tree[root].second;
    if (left == -1 && right == -1) {
        visited[root] = 1;
        in_v.push_back(root);
        return;
    }
    if ((left > -1) && (visited[left] == 0)) {
        in_order(left);
    }
    visited[root] = 1;
    in_v.push_back(root);
    if ((right > -1) && (visited[right] == 0)) {
        in_order(right);
    }
}
void post_order(int root) {
    memset(visited, 0, sizeof(visited));
    int left = tree[root].first;
    int right = tree[root].second;
    if (left == -1 && right == -1) {
        visited[root] = 1;
        post_v.push_back(root);
        return;
    }
    if ((left > -1) && (visited[left] == 0)) {
        post_order(left);
    }
    if ((right > -1) && (visited[right] == 0)) {
        post_order(right);
    }
    visited[root] = 1;
    post_v.push_back(root);
}

void output() {
    for (int n : pre_v) {
        cout << (char)(n + 65);
    }
    cout << "\n";
    for (int n : in_v) {
        cout << (char)(n + 65);
    }
    cout << "\n";
    for (int n : post_v) {
        cout << (char)(n + 65);
    }
}

int main() {
    input();

    pre_order(0);
    in_order(0);
    post_order(0);

    output();
    return 0;
}