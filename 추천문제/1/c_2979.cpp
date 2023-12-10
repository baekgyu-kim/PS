// 트럭 주차
#include <bits/stdc++.h>

int main() {
    int charge1, charge2, charge3;
    int a_in, a_out, b_in, b_out, c_in, c_out;
    std::cin >> charge1 >> charge2 >> charge3;
    std::cin >> a_in >> a_out;
    std::cin >> b_in >> b_out;
    std::cin >> c_in >> c_out;

    charge2 *= 2;
    charge3 *= 3;

    std::vector<int> all;
    all.push_back(a_in);
    all.push_back(a_out);
    all.push_back(b_in);
    all.push_back(b_out);
    all.push_back(c_in);
    all.push_back(c_out);
    sort(all.begin(), all.end());

    int charge[5][2];
    for (int i = 0; i < 5; i++) {
        int num = 0;
        int start = all[i];
        int end = all[i + 1];
        int m = end - start;
        if (a_in <= start && end <= a_out) {
            num += 1;
        }
        if (b_in <= start && end <= b_out) {
            num += 1;
        }
        if (c_in <= start && end <= c_out) {
            num += 1;
        }
        charge[i][0] = num;
        charge[i][1] = m;
    }

    int result = 0;
    for (int i = 0; i < 5; i++) {
        int num = charge[i][0];
        int m = charge[i][1];
        if (num == 3) {
            result += (charge3 * m);
        }
        if (num == 2) {
            result += (charge2 * m);
        }
        if (num == 1) {
            result += (charge1 * m);
        }
    }

    std::cout << result;

    return 0;
}