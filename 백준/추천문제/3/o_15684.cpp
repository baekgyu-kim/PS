#include <bits/stdc++.h>
using namespace std;
int a[32][12] = {0};
// 위에서 몇번째, 왼쪽에서 몇번째
vector<pair<int, int>> H;
int vertical, initial_horizontal_num, horizontal = 0;

bool is_okay_to_add_horizontal_line(int y, int x) {
    if (a[y][x] == 1 || a[y][x - 1] == 1 || a[y][x + 1] == 1) {
        return false;
    } else {
        return true;
    }
}

bool is_all_vertical_lines_from_i_to_i() {
    for (int i = 0; i < vertical; i++) {
        int current = i;
        for (int j = 0; j < horizontal; j++) {
            if (a[j][current] == 1) {
                current += 1;
            } else if (a[j][current - 1] == 1) {
                current -= 1;
            }
        }
        if (current != i) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> vertical >> initial_horizontal_num >> horizontal;
    int input1, input2;
    for (int i = 0; i < initial_horizontal_num; i++) {
        cin >> input1 >> input2;
        a[input1 - 1][input2 - 1] = 1;
    }
    if (is_all_vertical_lines_from_i_to_i()) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < horizontal; i++) {
        for (int j = 0; j < vertical - 1; j++) {
            if (!is_okay_to_add_horizontal_line(i, j)) {
                continue;
            }
            a[i][j] = 1;
            if (is_all_vertical_lines_from_i_to_i()) {
                cout << 1;
                return 0;
            }
            a[i][j] = 0;
        }
    }
    for (int i = 0; i < horizontal; i++) {
        for (int j = 0; j < vertical - 1; j++) {
            if (!is_okay_to_add_horizontal_line(i, j)) {
                continue;
            }
            a[i][j] = 1;
            for (int p = i; p < horizontal; p++) {
                for (int q = 0; q < vertical - 1; q++) {
                    if (!is_okay_to_add_horizontal_line(p, q)) {
                        continue;
                    }
                    a[p][q] = 1;
                    if (is_all_vertical_lines_from_i_to_i()) {
                        cout << 2;
                        return 0;
                    }
                    a[p][q] = 0;
                }
            }
            a[i][j] = 0;
        }
    }
    for (int i = 0; i < horizontal; i++) {
        for (int j = 0; j < vertical - 1; j++) {
            if (!is_okay_to_add_horizontal_line(i, j)) {
                continue;
            }
            a[i][j] = 1;
            for (int p = i; p < horizontal; p++) {
                for (int q = 0; q < vertical - 1; q++) {
                    if (!is_okay_to_add_horizontal_line(p, q)) {
                        continue;
                    }
                    a[p][q] = 1;
                    for (int t = p; t < horizontal; t++) {
                        for (int s = 0; s < vertical - 1; s++) {
                            if (!is_okay_to_add_horizontal_line(s, t)) {
                                continue;
                            }
                            a[s][t] = 1;
                            if (is_all_vertical_lines_from_i_to_i()) {
                                cout << 3;
                                return 0;
                            }
                            a[s][t] = 0;
                        }
                    }
                    a[p][q] = 0;
                }
            }
            a[i][j] = 0;
        }
    }

    cout << -1;
    return 0;
}