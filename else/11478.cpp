// 서로 다른 부분 문자열의 개수

#include <bits/stdc++.h>
using namespace std;

int main() { 
    string S = "";
    cin >> S;
    set<string> substrs;
    int S_len = S.length();
    for (int i = 1; i < S_len+1; i++){
        for (int j = 0; j < S_len + 1 - i; j++){
            string substr = S.substr(j, i);
            substrs.insert(substr);
        }
    }
    cout << substrs.size();
    return 0;
}