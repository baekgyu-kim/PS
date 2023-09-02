// 패션왕 신해빈

#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int test_case_num = 0;
    std::cin >> test_case_num;

    for (int i = 0; i < test_case_num; i++) {
        int num = 0;
        std::cin >> num;
        std::map<std::string, int> map;
        for (int i = 0; i < num; i++) {
            std::string name, category;
            std::cin >> name >> category;
            map[category] += 1;
        }
        int result = 1;
        for (std::pair<std::string, int> pair : map) {
            result *= (pair.second + 1);
        }
        result -= 1;
        std::cout << result << "\n";
    }
}
