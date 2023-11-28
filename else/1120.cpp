// 문자열
#include <bits/stdc++.h>
using namespace std;

string A, B;

int difference(const string &A, const string &B) {
    int result = 0;
    for (int i = 0; i < A.length(); i++) {
        if (A[i] != B[i]) {
            result += 1;
        }
    }
    return result;
}

int main() {
    cin >> A >> B;
    int size_diff = B.size() - A.size();
    vector<int> diff;

    for (int i = 0; i <= size_diff; i++) {
        string B_temp = B.substr(i, A.size());
        diff.push_back(difference(A, B_temp));
    }

    int result = *min_element(diff.begin(), diff.end());
    cout << result;

    return 0;
}
