#include <bits/stdc++.h>
using namespace std;
int N = 0;
vector<int> num;
vector<char> op;
int res = INT_MIN;

int calculate(char op, int n1, int n2) {
    if (op == '+') {
        return n1 + n2;
    } else if (op == '-') {
        return n1 - n2;
    } else if (op == '*') {
        return n1 * n2;
    }
}

void solve(int current_index, int cummulated_res) {
    // 현재의 index가 마지막 숫자인 경우
    if (current_index == num.size() - 1) {
        res = max(res, cummulated_res);
        return;
    }
    // 괄호 치려면 현재 index 포함해서 숫자 3개가 필요함
    if (current_index + 2 > num.size() - 1) {
        // 괄호 안침
        solve(current_index + 1, calculate(op[current_index], cummulated_res,
                                           num[current_index + 1]));
        return;
    } else {
        //괄호 안침
        solve(current_index + 1, calculate(op[current_index], cummulated_res,
                                           num[current_index + 1]));
        //괄호 침
        int next_parentheses_res =
            calculate(op[current_index + 1], num[current_index + 1],
                      num[current_index + 2]);
        solve(current_index + 2, calculate(op[current_index], cummulated_res,
                                           next_parentheses_res));
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    char c;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> c;
        if (i % 2 == 0) {
            num.push_back(c - 48);
        } else {
            op.push_back(c);
        }
    }
    solve(0, num[0]);
    cout << res;
    return 0;
}