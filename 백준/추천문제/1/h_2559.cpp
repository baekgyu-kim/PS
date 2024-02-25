// 수열

#include <bits/stdc++.h>

int main() {
    int N, k = 0;
    std::cin >> N;
    std::cin >> k;
    std::vector<int> temperature;
    for (int i = 0; i < N; i++) {
        int temp;
        std::cin >> temp;
        temperature.push_back(temp);
    }

    std::vector<int> prefix_sum;
    prefix_sum.push_back(temperature[0]);
    for (int i = 1; i < temperature.size(); i++) {
        prefix_sum.push_back(prefix_sum[i - 1] + temperature[i]);
    }

    std::vector<int> k_sum;
    k_sum.push_back(prefix_sum[k - 1]);
    for (int i = 1; i < temperature.size() - k + 1; i++) {
        int temp = prefix_sum[i + k - 1] - prefix_sum[i - 1];
        k_sum.push_back(temp);
    }

    int max = *max_element(k_sum.begin(), k_sum.end());
    std::cout << max;
    return 0;
}