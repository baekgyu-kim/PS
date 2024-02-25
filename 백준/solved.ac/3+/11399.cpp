#include<bits/stdc++.h>
using namespace std;
int N = 0;
int P[1004] = {0};
int sum[1004] = {0};
int main() {
    cin >> N;
    int p = 0;
    for (int i = 0; i < N; i++) {
        cin >> p;
        P[i] = p;
    }
    sort(P, P + N);
    sum[0] = P[0];
    for (int i = 1; i < N; i++) {
        sum[i] = P[i] + sum[i - 1];
    }
    int result = 0;
    for (int i = 0; i < N; i++){
        result += sum[i];
    }
    cout << result;
}