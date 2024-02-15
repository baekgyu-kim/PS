#include <bits/stdc++.h>
using namespace std;
int N = 0;

// tree[0] : root node
vector<int> tree[54];
set<int> leaf;

bool is_leaf(int node) {
    if (tree[node].size() == 0) {
        return true;
    } else {
        return false;
    }
}

void delete_target(int target) {
    if (is_leaf(target) == true) {
        leaf.erase(target);
        return;
    }
    for (int child : tree[target]) {
        delete_target(child);
    }
}

bool is_target_only_child(int target) {
    for (int node = 0; node < N; node++) {
        vector<int> children = tree[node];
        if (find(children.begin(), children.end(), target) != children.end() &&
            children.size() == 1) {
            return true;
        }
    }
    return false;
}

int main() {
    cin >> N;
    int parent = 0;
    for (int i = 0; i < N; i++) {
        cin >> parent;
        if (parent == -1) {
            continue;
        }
        tree[parent].push_back(i);
    }
    int target = 0;
    cin >> target;
    for (int i = 0; i < N; i++) {
        if (is_leaf(i) == true) {
            leaf.insert(i);
        }
    }
    delete_target(target);

    if (is_target_only_child(target) == true) {
        cout << leaf.size() + 1;
    } else {
        cout << leaf.size();
    }

    return 0;
}