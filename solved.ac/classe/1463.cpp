// 1로 만들기

#include <bits/stdc++.h>
using namespace std;
int a[1000004] = {0};
int main() {
    int N = 0;
    cin >> N;
    a[2] = 1;
    a[3] = 1;
    for (int i = 4; i < N + 1; i++){
        int steps = a[i - 1] + 1;
        if(i%3 == 0){
            steps = min(steps, a[i / 3] + 1);
        }
        if(i%2 == 0){
            steps = min(steps, a[i / 2] + 1);
        }
        a[i] = steps;
    }
    cout << a[N];
    return 0;
}