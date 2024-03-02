#include <bits/stdc++.h>
using namespace std;
string s1 = "";
string s2 = "";
int N1, N2 = 0;
int dp[1004][1004] = {0};
int main() {
    cin >> s1 >> s2;
    N1 = s1.size();
    N2 = s2.size();
    for (int i = 1; i <= N1; i++) {
        for (int j = 1; j <= N2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[N1][N2];
    return 0;
}