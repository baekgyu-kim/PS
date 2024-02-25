// 영화감독 숌

#include <bits/stdc++.h>
using namespace std;

int N = 0;

int first3 = 1;
int first4 = 2;
int first5 = 20;
int first6 = 281;
int first7 = 3701;

int return_digit(int n) {
    if (n < first4) {
        return 3;
    } else if (n < first5) {
        return 4;
    } else if (n < first6) {
        return 5;
    } else if(n < first7) {
        return 6;
    }else{
        return 7;
    }
}

int digit4(int seq) {
    int count = 0;
    for (int i = 1666; i <= 9666; i++) {
        int temp = i;
        int d = temp % 10;
        temp /= 10;
        int c = temp % 10;
        temp /= 10;
        int b = temp % 10;
        temp /= 10;
        int a = temp;
        if ((a == 6 && b == 6 && c == 6) || (b == 6 && c == 6 && d == 6)) {
            count++;
            if (count == seq) {
                return i;
            }
        }
    }
}
int digit5(int seq) {
    int count = 0;
    for (int i = 10666; i <= 99666; i++) {
        int temp = i;
        int e = temp % 10;
        temp /= 10;
        int d = temp % 10;
        temp /= 10;
        int c = temp % 10;
        temp /= 10;
        int b = temp % 10;
        temp /= 10;
        int a = temp;
        int six_num = 0;
        if ((a == 6 && b == 6 && c == 6) || (b == 6 && c == 6 && d == 6) ||
            (c == 6 && d == 6 && e == 6)) {
            count++;
            if (count == seq) {
                return i;
            }
        }
    }
}
int digit6(int seq) {
    int count = 0;
    for (int i = 100666; i <= 999666; i++) {
        int temp = i;
        int f = temp % 10;
        temp /= 10;
        int e = temp % 10;
        temp /= 10;
        int d = temp % 10;
        temp /= 10;
        int c = temp % 10;
        temp /= 10;
        int b = temp % 10;
        temp /= 10;
        int a = temp;
        if ((a == 6 && b == 6 && c == 6) || (b == 6 && c == 6 && d == 6) ||
            (c == 6 && d == 6 && e == 6) || (d == 6 && e == 6 && f == 6)) {
            count++;
            if (count == seq) {
                return i;
            }
        }
    }
}

int digit7(int seq) {
    int count = 0;
    for (int i = 1000666; i <= 9999666; i++) {
        int temp = i;
        int g = temp % 10;
        temp /= 10;
        int f = temp % 10;
        temp /= 10;
        int e = temp % 10;
        temp /= 10;
        int d = temp % 10;
        temp /= 10;
        int c = temp % 10;
        temp /= 10;
        int b = temp % 10;
        temp /= 10;
        int a = temp;
        if ((a == 6 && b == 6 && c == 6) || (b == 6 && c == 6 && d == 6) ||
            (c == 6 && d == 6 && e == 6) || (d == 6 && e == 6 && f == 6) ||
            (e == 6 && f == 6 && g == 6)) {
            count++;
            if (count == seq) {
                return i;
            }
        }
    }
}

int main() {
    cin >> N;
    int digit = return_digit(N);
    int result = 0;

    // 0부터 센 순서

    if (digit == 3) {
        result = 666;
    } else if (digit == 4) {
        int seq_in_digit = N - first4 + 1;
        result = digit4(seq_in_digit);
    } else if (digit == 5) {
        int seq_in_digit = N - first5 + 1;
        result = digit5(seq_in_digit);
    } else if (digit == 6) {
        int seq_in_digit = N - first6 + 1;
        result = digit6(seq_in_digit);
    }else{
        int seq_in_digit = N - first7 + 1;
        result = digit7(seq_in_digit);
    }

    cout << result;
    return 0;
}