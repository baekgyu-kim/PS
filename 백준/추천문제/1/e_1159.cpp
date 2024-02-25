// 농구 경기

#include <bits/stdc++.h>

int main() {
    int num = 0;
    std::cin >> num;
    std::vector<std::string> player;
    for (int i = 0; i < num; i++) {
        std::string temp;
        std::cin >> temp;
        player.push_back(temp);
    }

    std::map<char, int> map;
    for (int i = 97; i < 123; i++) {
        map.insert(std::pair<char, int>(i, 0));
    }

    for (int i = 0; i < player.size(); i++) {
        char temp = player[i][0];
        map[temp] += 1;
    }
    std::map<char, int>::iterator iter = map.begin();
    std::vector<char> result_v;

    while (iter != map.end()) {
        char first_char = iter->first;
        int num = iter->second;
        if (num >= 5) {
            result_v.push_back(first_char);
        }
        ++iter;
    }

    if (result_v.size() == 0) {
        std::cout << "PREDAJA";
    } else {
        sort(result_v.begin(), result_v.end());
        for (int i = 0; i < result_v.size(); i++) {
            std::cout << result_v[i];
        }
    }

    return 0;
}