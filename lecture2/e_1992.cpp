// 쿼드트리

#include <bits/stdc++.h>
using namespace std;

int N;
int a[64][64] = {0};

string encode(int left, int right, int top, int bottom) {
    string encoded_result = "";
    bool is_all_0 = true;
    bool is_all_1 = true;
    for (int i = top; i <= bottom; i++) {
        for (int j = left; j <= right; j++) {
            if (a[i][j] == 0) {
                is_all_1 = false;
            }
            if (a[i][j] == 1) {
                is_all_0 = false;
            }
        }
    }
    if (is_all_0) {
        encoded_result = "0";
    } else if (is_all_1) {
        encoded_result = "1";
    } else {
        encoded_result.append("(");
        encoded_result.append(
            encode(left, (left + right - 1) / 2, top, (top + bottom - 1) / 2));
        encoded_result.append(
            encode((left + right + 1) / 2, right, top, (top + bottom - 1) / 2));
        encoded_result.append(
            encode(left, (left + right - 1) / 2, (top + bottom + 1) / 2, bottom));
        encoded_result.append(
            encode((left + right + 1) / 2, right, (top + bottom + 1) / 2, bottom));
        encoded_result.append(")");
    }
    return encoded_result;
}

int main() {
    cin >> N;
    string temp = "";
    for (int i = 0; i < N; i++) {
        cin >> temp;
        for (int j = 0; j < N; j++){
            if(temp[j] == '0'){
                a[i][j] = 0;
            }else{
                a[i][j] = 1;
            }
        }
    }

    string result = encode(0, N - 1, 0, N - 1);
    cout << result;

    return 0;
}