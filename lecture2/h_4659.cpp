// 비밀번호 발음하기

#include <bits/stdc++.h>
using namespace std;

bool is_vowels(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        return true;
    } else {
        return false;
    }
}

bool is_acceptable(string pw) {
    bool contains_vowel = false;
    int v_count = 0;
    int c_count = 0;
    char prev = pw[0];
    bool e_already_twice = false;
    bool o_already_twice = false;
    if (is_vowels(prev) == true) {
        contains_vowel = true;
        v_count++;
        c_count = 0;
    } else {
        v_count = 0;
        c_count++;
    }
    for (int i = 1; i < pw.size(); i++) {
        if (pw[i] == prev) {
            if (pw[i] == 'e' && e_already_twice == false) {
                e_already_twice = true;
                continue;
            } else if (pw[i] == 'o' && o_already_twice == false) {
                o_already_twice = true;
                continue;
            } else {
                return false;
            }
        } else {
            e_already_twice = false;
            o_already_twice = false;
        }
        if (v_count == 3 || c_count == 3) {
            return false;
        }
        if (is_vowels(pw[i]) == true) {
            contains_vowel = true;
            v_count++;
            c_count = 0;
        } else {
            v_count = 0;
            c_count++;
        }
        prev = pw[i];
    }
    if (v_count == 3 || c_count == 3) {
        return false;
    }
    if (contains_vowel == false) {
        return false;
    }
    return true;
}

string pw = "";
vector<string> pws;

int main() {
    while (true) {
        cin >> pw;
        if (pw == "end") {
            break;
        }
        pws.push_back(pw);
    }
    for (int i = 0; i < pws.size(); i++) {
        string result = "";
        string pw = pws[i];
        result.append("<");
        result.append(pw);
        result.append(">");
        if (is_acceptable(pws[i])) {
            result.append(" is acceptable.");
        } else {
            result.append(" is not acceptable.");
        }
        cout << result << "\n";
    }
    return 0;
}