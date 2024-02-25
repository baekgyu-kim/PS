// 더하기 사이클 

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N = 0;
    if(N < 10){
        N = N * 10;
    }
    cin >> N;
    int N_copy = N;
    int count = 0;
    while(true){
        int ten = N_copy / 10;
        int one = N_copy % 10;
        int temp = (ten + one) % 10;
        N_copy = (one * 10) + temp;
        count++;
        if (N_copy == N) {
            break;
        }
    }
    cout << count;
}