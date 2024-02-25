#include <bits/stdc++.h>
using namespace std;
int N = 0;
int cnt = 0;
vector<pair<int, int> > v;

bool cmp(pair<int, int> a, pair<int, int> b) { 
    if(a.second == b.second){
        return a.first < b.first;
    }else{
        return a.second < b.second;
    }
    
}

int main() {
    cin >> N;
    int start, end = 0;
    for (int i = 0; i < N; i++) {
        cin >> start >> end;
        v.push_back(make_pair(start, end));
    }
    sort(v.begin(), v.end(), cmp);
    int time = v[0].second;
    cnt++;
    for (int i = 1; i < N; i++){
        if(time <= v[i].first){
            time = v[i].second;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}