// 1

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 0;
    while (scanf("%d", &n) != EOF) {
        int num = 1;
        int digit = 1;
        while (true) {
            // num이 n의 배수이면 digit을 print
            if (num % n == 0) {
                cout << digit <<"\n";
                break;
            }
            // 아니면 num에 1을 하나 더 붙이고 digit 값을 하나 늘림
            else {
                // modulo 연산은 덧셈과 곱셈에서 분배법칙 성림
                num = ((num % n) * (10 % n)) + 1;
                digit = digit + 1;
            }
        }
    }
    return 0;
}