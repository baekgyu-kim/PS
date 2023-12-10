// 곱셈

#include <bits/stdc++.h>

using namespace std;

long long power(long long A, long long B, long long C) {
    if (B == 1){
        return A % C;
    }
    // A의 B승은 (A의 (B/2)승 * A의 (B/2)승)
    long long temp = power(A, (B / 2), C);
    temp = (temp * temp)%C;

    // 지수가 홀수인 경우 한 번 더 곱해줘야 함
    if((B % 2) == 1){
        temp = ((temp * A )% C);
    }
    return temp;
}

int main() {
    long long A, B, C = 0;
    cin >> A >> B >> C;
    cout << power(A, B, C) << "\n";

    return 0;
}