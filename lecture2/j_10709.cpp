#include <bits/stdc++.h>
using namespace std;
int H, W;
int a[200][200];

void when_cloud_is_found(int i, int j){
    int cnt = 1;
    while (a[i][j + 1] == -1) {
        a[i][j + 1] = cnt++;
        j++;
    }
}
int main() {
    cin >> H >> W;
    string s;
    for (int i = 0; i < H; i++) {
        cin >> s;
        for (int j = 0; j < W; j++) {
            if (s[j] == '.')
                a[i][j] = -1;
            else
                a[i][j] = 0;
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (a[i][j] == 0) {
                when_cloud_is_found(i, j);
            }
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++)
            cout << a[i][j] << " ";
        cout << "\n";
    }
    return 0;
}