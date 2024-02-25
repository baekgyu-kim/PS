#include <bits/stdc++.h>
using namespace std;

int a[130][130] = {0};
int N, zero, one = 0;

bool is_all_same_color(int top, int left, int length) {
    int first_elem = a[top][left];
    for (int i = top; i < top + length; i++) {
        for (int j = left; j < left + length; j++) {
            if (a[i][j] != first_elem) {
                return false;
            }
        }
    }
    return true;
}

void make_quarter(int top, int left, int length) {
    if (is_all_same_color(top, left, length) == true) {
        if (a[top][left] == 0) {
            zero++;
        } else {
            one++;
        }
        return;
    }
    make_quarter(top, left, length / 2);
    make_quarter(top, left + length / 2, length / 2);
    make_quarter(top + length / 2, left, length / 2);
    make_quarter(top + length / 2, left + length / 2, length / 2);
}

int main() {
    cin >> N;
    int x = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> x;
            a[i][j] = x;
        }
    }
    make_quarter(0, 0, N);
    cout << zero << "\n" << one << "\n";
    return 0;
}