#include<bits/stdc++.h>
using namespace std;
int N, M = 0;
vector<string> havent_heard;
vector<string> havent_met;

int main() { 
    cin >> N >> M;
    string name = "";
    for (int i = 0; i < N; i++) {
        cin >> name;
        havent_heard.push_back(name);
    }
    for (int i = 0; i < M; i++){
        cin >> name;
        havent_met.push_back(name);
    }
    sort(havent_heard.begin(), havent_heard.end());
    sort(havent_met.begin(), havent_met.end());

    vector<string> intersection(1000000);
    auto intersection_end =
        set_intersection(havent_heard.begin(), havent_heard.end(),
                         havent_met.begin(), havent_met.end(), intersection.begin());
    intersection.resize(intersection_end - intersection.begin());
    cout << intersection.size() << "\n";
    for (string name : intersection) {
        cout << name << "\n";
    }
}