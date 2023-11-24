// 수 찾기

#include <bits/stdc++.h>
using namespace std;

int N = 0;
int M = 0;
int A[100000];

int binary_search(int m) {
    int start_index = 0;
    int end_index = N - 1;
    while(true){
        if(start_index > end_index){
            cout << 0 << "\n";
            return 0;
        }
        int middle_index = (start_index + end_index) / 2;
        int middle_value = A[middle_index];
        if (middle_value == m) {
            cout << 1 << "\n";
            return 0;
        } else if (m < middle_value) {
            end_index = middle_index - 1;
        } else if (middle_value < m) {
            start_index = middle_index + 1;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    cin >> N;
    int temp = 0;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        A[i] = temp;
    }
    sort(A, A + N);
    cin >> M;
    int m = 0;
    for (int i = 0; i < M; i++) {
        cin >> m;
        binary_search(m);
    }

    return 0;
}