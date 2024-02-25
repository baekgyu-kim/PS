// 펠린드롬

#include <bits/stdc++.h>

int main() {
    std::string s;
    std::cin >> s;

    int result = 1;
    int length = s.length();

    if (length % 2 == 0) {
        for (int i = 0; i < length / 2; i++) {
            if (s[i] != s[length - 1 - i]) {
                result = 0;
            }
        }
    } else {
        for (int i = 0; i < (length - 1) / 2; i++) {
            if (s[i] != s[length - 1 - i]) {
                result = 0;
            }
        }
    }

    std::cout << result;

    return 0;
}