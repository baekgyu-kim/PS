// 피보나치 함수
#include<bits/stdc++.h>
using namespace std;
int T = 0;
vector<int> v;
vector<pair<int, int> > result;

pair<int, int> calculate_one(int n){
    if(n == 0){
        return make_pair(1, 0);
    }
    if (n == 1) {
        return make_pair(0, 1);
    }
    pair<int, int> n_minus_one;
    pair<int, int> n_minus_two;
    if (result[n - 1].first != -1 and result[n - 1].second != -1) {
        n_minus_one = result[n - 1];
    } else {
        n_minus_one = calculate_one(n - 1);
    }
    if (result[n - 2].first != -1 and result[n - 2].second != -1) {
        n_minus_two = result[n - 2];
    } else {
        n_minus_two = calculate_one(n - 2);
    }
    return make_pair(n_minus_one.first + n_minus_two.first,
                     n_minus_one.second + n_minus_two.second);
}

void calculate_all_cases() { 
    for (int i = 0; i <= 40; i++){
        result[i]=(calculate_one(i));
    }
}

int main() {
    for (int i = 0; i <= 40; i++){
        result.push_back(make_pair(-1, -1));
    }
    calculate_all_cases();
    cin >> T;
    int test_case = 0;
    for (int i = 0; i < T; i++) {
        cin >> test_case;
        v.push_back(test_case);
    }
    for (int n : v){
        pair<int, int> p = result[n];
        cout << p.first << " " << p.second << "\n";
    }
}