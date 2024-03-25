#include <bits/stdc++.h>
using namespace std;

int N, X = 0;
vector<int> v;
int res = 0;

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    int temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    cin >> X;
}

int main() {
    input();
    sort(v.begin(), v.end());
    int start = 0;
    int end = N - 1;
    while(start < end){
        int sum = v[start] + v[end];
        if (sum == X) {
            res++;
            start++;
            end--;
        } else if (sum < X){
            start++;
        }else if (sum > X){
            end--;
        }
    }
    cout << res;
    return 0;
}