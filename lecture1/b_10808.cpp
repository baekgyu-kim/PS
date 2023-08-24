// 알파벳 개수
#include <bits/stdc++.h>

int main() {
    std::map<char, int> map;
    for (int i = 97; i < 123; i++) {
        map.insert(std::pair<char, int>(i, 0));
    }
    std::string str;
    std::cin >> str;

    for (int i = 0; i < str.length(); i++) {
        int temp = str[i];
        map[temp] += 1;
    }

    for (int i = 97; i < 123; i++) {
        std::cout << map[i] << " ";
    }

    return 0;
}
