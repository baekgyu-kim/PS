#include <bits/stdc++.h>

using namespace std;

int height = INT_MIN;
int width = INT_MIN;

int solution(vector<vector<int>> sizes) {
    for (auto v : sizes) {
        if (v[0] > v[1]) {
            height = max(height, v[0]);
            width = max(width, v[1]);
        } else {
            height = max(height, v[1]);
            width = max(width, v[0]);
        }
    }
    return height * width;
}