#include <bits/stdc++.h>
using namespace std;
int T = 0;
vector<pair<bool,deque<int>>> res;
string func;
int N;
deque<int> dq;
bool is_reversed = false;

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> func;
    cin >> N;
    dq.clear();
    string s;
    cin >> s;
    char c;
    int n;
    stringstream ss(s);
    while(ss >> c && c == '['){
        while(ss >> n){
            dq.push_back(n);
            ss >> c;
            if(c == ']'){
                break;
            }
        }
    }
}


void solve() {
    input();
    is_reversed = false;
    for (int i = 0; i < func.size(); i++) {
        int c = func[i];
        if (dq.size() == 0 && c == 'D') {
            deque<int> temp;
            temp.push_back(0);
            res.push_back({false, temp});
            return;
        }
        if (c == 'D') {
            if(is_reversed){
                dq.pop_back();
            }else{
                dq.pop_front();
            }
        } else {
            if(is_reversed == true){
                is_reversed = false;
            }else{
                is_reversed = true;
            }
        }
    }
    res.push_back({is_reversed, dq});
}

void print(bool is_reversed, deque<int> q) {
    if (q.size() == 1 && q.front() == 0) {
        cout << "error\n";
    } else if (q.size() == 0) {
        cout << "[]\n";
    } else {
        if(is_reversed){
            cout << '[';
            for (int i = q.size() - 1; i >= 0; i--) {
                if (i == 0) {
                    cout << q[i] << "]\n";
                } else {
                    cout << q[i] << ",";
                }
            }
        }else{
            cout << '[';
            for (int i = 0; i < q.size(); i++) {
                if (i < q.size() - 1) {
                    cout << q[i] << ",";
                } else {
                    cout << q[i] << "]\n";
                }
            }
        }
    }
}

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        solve();
    }
    for (auto p : res) {
        print(p.first, p.second);
    }
    return 0;
}