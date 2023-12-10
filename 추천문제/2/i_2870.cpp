// 수학 숙제

#include <bits/stdc++.h>
using namespace std;

int N = 0;
vector<string> strings;
queue<char> q;
vector<string> n;

void add_number_to_n(){
    if (q.empty() == false) {
        string num = "";
        int q_size = q.size();
        for (int i = 0; i < q_size; i++) {
            num.push_back(q.front());
            q.pop();
        }
        bool is_all_0 = true;
        bool is_num_before_0 = false;
        string new_num = "";
        for (int i = 0; i < num.size(); i++) {
            if (num[i] != '0') {
                is_all_0 = false;
                is_num_before_0 = true;
                new_num.push_back(num[i]);
            }
            if (num[i] == '0' && is_num_before_0 == true) {
                new_num.push_back(num[i]);
            }
            if (num[i] == '0' && is_num_before_0 == false) {
                continue;
            }
        }
        if (is_all_0 == true) {
            new_num = "0";
        }
        if (num != "") {
            n.push_back(new_num);
        }
    }
}

bool cmp(string a, string b) {
    if (a.size() == b.size()) {
        for (int i = 0; i < a.size(); i++) {
            if (int(a[i]) == int(b[i])) {
                continue;
            } else {
                return int(a[i]) < int(b[i]);
            }
        }
    } else {
        return a.size() < b.size();
    }
}

int main() {
    cin >> N;
    string temp = "";
    for (int i = 0; i < N; i++) {
        cin >> temp;
        strings.push_back(temp);
    }
    for (string s : strings) {
        for (char c : s) {
            if (c == '0') {
                q.push('0');
            } else if (c == '1') {
                q.push('1');
            } else if (c == '2') {
                q.push('2');
            } else if (c == '3') {
                q.push('3');
            } else if (c == '4') {
                q.push('4');
            } else if (c == '5') {
                q.push('5');
            } else if (c == '6') {
                q.push('6');
            } else if (c == '7') {
                q.push('7');
            } else if (c == '8') {
                q.push('8');
            } else if (c == '9') {
                q.push('9');
            } else {
                add_number_to_n();
            }
        }
        add_number_to_n();
    }
    sort(n.begin(), n.end(), cmp);
    for (int i = 0; i < n.size(); i++) {
        cout << n[i] << "\n";
    }
    return 0;
}