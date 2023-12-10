// 나는야 포켓몬 마스터 이다솜

#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int N, M = 0;
    std::string s;
    std::cin >> N >> M;

    std::map<int, std::string> num_name;
    std::map<std::string, int> name_num;

    for (int i = 0; i < N; i++) {
        std::cin >> s;
        num_name[i + 1] = s;
        name_num[s] = i + 1;
    }

    for (int i = 0; i < M; i++) {
        std::cin >> s;
        if (atoi(s.c_str()) == 0) {
            std::cout << name_num[s] << "\n";

        } else {
            std::cout << num_name[atoi(s.c_str())] << "\n";
        }
    }
    return 0;
}