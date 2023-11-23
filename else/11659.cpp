// 구간 합 구하기 4

#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int N, M = 0;
    cin >> N >> M;
    int ith_sum[N + 1];
    ith_sum[0] = 0;
    int sum = 0;
    int temp = 0;
    for (int i = 1; i < N + 1; i++) {
        cin >> temp;
        sum += temp;
        ith_sum[i] = sum;
    }
    int start = 0;
    int end = 0;
    for (int i = 0; i < M; i++) {
        cin >> start >> end;
        cout << ith_sum[end] - ith_sum[start - 1] << "\n";
    }
    return 0;
}