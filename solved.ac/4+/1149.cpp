#include <bits/stdc++.h>
using namespace std;
int N = 0;
// 빨 초 파
int cost[1004][3] = {0};
int selected[1004][3] = {0};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> cost[i][j];
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            int option1, option2 = 0;
            if (j == 0) {
                option1 = 1;
                option2 = 2;
            } else if (j == 1) {
                option1 = 0;
                option2 = 2;
            } else {
                option1 = 0;
                option2 = 1;
            }
            selected[i][j] =
                min(selected[i - 1][option1], selected[i - 1][option2]) +
                cost[i][j];
        }
    }
    int *Nth_house_cost = selected[N];
    cout << min(Nth_house_cost[0], min(Nth_house_cost[1], Nth_house_cost[2]));
    return 0;
}