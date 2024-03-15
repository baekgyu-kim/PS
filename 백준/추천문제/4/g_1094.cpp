#include <bits/stdc++.h>
using namespace std;
int X = 0;
int res = 1;

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> X;
}

int main() {
    input();
    while (X > 1) {
        if (X & 1){
            res++;
        }
        X /= 2;
    }
    cout << res;
    return 0;
}