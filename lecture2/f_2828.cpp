// 사과 담기 게임

#include <bits/stdc++.h>
using namespace std;

int M, N, J = 0;

int main() {
    cin >> N >> M;
    int left = 0;
    int right = M - 1;
    cin >> J;
    int apple = 0;
    int count = 0;
    for (int i = 0; i < J; i++) {
        cin >> apple;
        apple -= 1;
        if (left <= apple && apple <= right) {
            continue;
        } else if (apple < left) {
            int move = left - apple;
            count += move;
            left -= move;
            right -= move;
        } else if (right < apple) {
            int move = apple - right;
            count += move;
            left += move;
            right += move;
        }
    }
    cout << count;
    return 0;
}