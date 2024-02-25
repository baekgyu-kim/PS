// Z

#include <bits/stdc++.h>
using namespace std;
int N, r, c = 0;
int result = 0;


void calculate(int top_y, int left_x, int length) {
    int square_size = length * length;
    if (square_size == 1 && r == top_y && c == left_x) {
        cout << result;
        return;
    }
    if (top_y <= r && r < top_y + length && left_x <= c && c < left_x + length) {
        calculate(top_y, left_x, length / 2);
        calculate(top_y, left_x + length / 2, length / 2);
        calculate(top_y + length / 2, left_x, length / 2);
        calculate(top_y + length / 2, left_x + length / 2, length / 2);
    } else {
        result += square_size;
    }
}

int main() {
    cin >> N >> r >> c;
    int l = pow(2, N);
    calculate(0, 0, l);
    return 0;
}