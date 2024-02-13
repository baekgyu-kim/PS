#include<bits/stdc++.h>
using namespace std;

int N, x = 0;
priority_queue<int, vector<int>, greater<int> > q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> x;
        if(x == 0){
            if(q.empty() == true){
                cout << 0 << "\n";
            }else{
                cout << q.top() << "\n";
                q.pop();
            }
        }else{
            q.push(x);
        }
    }
    return 0;
}