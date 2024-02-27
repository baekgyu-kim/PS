#include <bits/stdc++.h>

using namespace std;
unordered_map<string, int> m;
bool solution(vector<string> v) {
    string n = "";
    for (string n : v) {
        m[n] = 1;
    }
    for (string current_phone_num : v) {
        n = "";
        for (char c : current_phone_num) {
            n += c;
            if (m[n] == 1 && n != current_phone_num) {
                return false;
            }
        }
    }
    return true;
}