// 색종이

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    int paper[100][100] = {0};
    int left = 0;
    int bottom = 0;
    for (int i = 0; i < n; i++) {
        cin >> left >> bottom;
        int right = left + 9;
        int top = bottom + 9;
        for (int y = top; y >= bottom; y--){
            for (int x = left; x <= right; x++){
                paper[x][y] = 1;
            }
        }
    }
    int s = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++){
            if(paper[i][j]==1){
                s++;
            }
        }
    }
    cout << s;
    return 0;
}