// 주몽

#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> numbers;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        numbers.push_back(temp);
    }
    int result = 0;
    if(N < 2){
        cout << result;
        return 0;
    }
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (numbers[i] + numbers[j] == M) {
                result += 1;
            }
        }
    }
    cout << result;
    return 0;
}