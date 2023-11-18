// 분해합

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N = 0;
    cin >> N;
    for (int i = 0; i < N; i++){
        int ith_num = i;
        int sum = i;
        while(ith_num != 0){
            sum += ith_num % 10;
            ith_num /= 10;
        }
        if(sum == N){
            cout << i << '\n';
            return 0;
        }
    }
    cout << 0 << '\n';
    return 0;
}