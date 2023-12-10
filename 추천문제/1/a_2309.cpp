// 일곱 난쟁이

#include <bits/stdc++.h>

int main() {
    std::vector<int> v;
    for (int i = 0; i < 9; i++) {
        int temp = 0;
        std::cin >> temp;
        v.push_back(temp);
    }

    int sum = std::accumulate(v.begin(), v.end(), 0);

    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (sum - v[i] - v[j] == 100) {
                int spy = v[j];
                v.erase(v.begin() + i);
                v.erase(find(v.begin(), v.end(), spy));
                sort(v.begin(), v.end());
                for (int k = 0; k < v.size(); k++) {
                    std::cout << v[k] << std::endl;
                }
                return 0;
            }
        }
    }
}