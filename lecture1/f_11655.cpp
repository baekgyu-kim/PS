// ROT13

#include <bits/stdc++.h>

int is_alphabet(int i) {
    if ((i >= 65 && i <= 90) || (i >= 97 && i <= 122)) {
        return 1;
    } else {
        return 0;
    }
}

int is_capital(int i) {
    if (i >= 65 && i <= 90) {
        return 1;

    } else {
        return 0;
    }
}

int main() {
    int capital_start = 65;
    int capital_end = 90;
    int small_start = 97;
    int small_end = 122;

    std::string s;
    getline(std::cin, s);
    for (int i = 0; i < s.length(); i++) {
        int ith_char_int = int(s[i]);
        if (is_alphabet(ith_char_int)) {
            int temp = ith_char_int + 13;
            if (is_capital(ith_char_int) == 1 && temp > 90) {
                temp -= 26;
            } else if (is_capital(ith_char_int) == 0 && temp > 122) {
                temp -= 26;
            }
            s[i] = char(temp);

        } else {
            continue;
        }
    }

    std::cout << s;
    return 0;
}