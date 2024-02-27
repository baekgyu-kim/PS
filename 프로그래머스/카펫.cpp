#include <bits/stdc++.h>

using namespace std;

vector<int> res;
int s = 0;

bool cmp(int a, int b) { return a > b; }

vector<int> solution(int brown, int yellow) {
    s = brown + yellow;
    int h = 3;
    while (s / h >= 3) {
        if (s % h > 0) {
            h++;
            continue;
        }
        int l = s / h;
        int y = (l - 2) * (h - 2);
        cout << "h : " << h << " l : " << l << " y : " << y << "\n";
        if (y == yellow) {
            res.push_back(l);
            res.push_back(h);
            break;
        }
        h++;
    }

    sort(res.begin(), res.end(), cmp);
    return res;
}