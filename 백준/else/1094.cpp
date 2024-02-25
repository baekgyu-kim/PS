// 막대기

#include <bits/stdc++.h>
using namespace std;
int main() {
    int X = 0;
    cin >> X;
    int sticks[] = {64, 32, 16, 8, 4, 2, 1};
    int answer = 0;
    for (int ith_stick : sticks){
        if (X >= ith_stick) {
            X = X - ith_stick;
            answer++;
        }
        if(X==0){
            cout << answer;
            break;
        }
    }

    return 0;
}