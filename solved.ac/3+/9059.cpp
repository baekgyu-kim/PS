#include<bits/stdc++.h>
using namespace std;
int T = 0;
int a[13] = {0};
int last = 0;
vector<int> v;

int cases(int n){
    if(n <= last){
        return a[n];
    }
    while(n > last){
        a[last + 1] = a[last] + a[last - 1] + a[last - 2];
        last++;
    }
    return a[n];
}

int main() {
    cin >> T;
    int testcase = 0;
    a[1] = 1;
    a[2] = 2;
    a[3] = 4;
    last = 3;
    for (int i = 0; i < T; i++) {
        cin >> testcase;
        v.push_back(testcase);
    }
    for (int i = 0; i < T; i++){
        cout << cases(v[i]) << "\n";
    }
        return 0;
}