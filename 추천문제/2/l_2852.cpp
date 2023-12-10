// NBA 농구

#include <bits/stdc++.h>
using namespace std;

int N = 0;
map<int, int> m;
map<int, int> score;

vector<int> sec_to_minsec(int s) {
    int min = s / 60;
    int sec = s % 60;
    vector<int> result;
    result.push_back(min);
    result.push_back(sec);
    return result;
}

int main() {
    cin >> N;
    m[1] = 0;
    m[2] = 0;

    score[1] = 0;
    score[2] = 0;

    vector<vector<int> > scoreboard(N + 2, vector<int>(2, 0));

    scoreboard[0][0] = 0;
    scoreboard[0][1] = 0;

    scoreboard[N + 1][0] = 0;
    scoreboard[N + 1][1] = 48 * 60;

    int team_number;
    char m1;
    char m2;
    char colon;
    char s1;
    char s2;
    for (int i = 1; i <= N; i++) {
        cin >> team_number;
        cin >> m1 >> m2 >> colon >> s1 >> s2;
        int min = (int(m1) - 48) * 10 + (int(m2) - 48);
        int sec = (int(s1) - 48) * 10 + (int(s2) - 48);
        scoreboard[i][0] = team_number;
        scoreboard[i][1] = min * 60 + sec;
    }

    for (int i = 1; i < N + 2; i++) {
        int ith_team = scoreboard[i][0];
        if (score[1] > score[2]) {
            score[ith_team] = score[ith_team] + 1;
            m[1] = m[1] + (scoreboard[i][1] - scoreboard[i - 1][1]);
        } else if (score[1] < score[2]) {
            score[ith_team] = score[ith_team] + 1;
            m[2] = m[2] + (scoreboard[i][1] - scoreboard[i - 1][1]);
        } else {
            score[ith_team] = score[ith_team] + 1;
        }
    }

    vector<int> team1 = sec_to_minsec(m[1]);
    vector<int> team2 = sec_to_minsec(m[2]);

    string team1_min = to_string(team1[0]);
    string team1_sec = to_string(team1[1]);
    string team2_min = to_string(team2[0]);
    string team2_sec = to_string(team2[1]);

    if(team1_min == "0"){
        team1_min = "00";
    }
    if (team1_sec == "0") {
        team1_sec = "00";
    }
    if (team2_min == "0") {
        team2_min = "00";
    }
    if (team2_sec == "0") {
        team2_sec = "00";
    }

    string temp[4] = {team1_min, team1_sec, team2_min, team2_sec};
    for (int i = 0; i < 4; i++){
        if(temp[i].size() == 1){
            temp[i] = "0" + temp[i];
        }
    }

    cout << temp[0] << ":" << temp[1] << "\n";
    cout << temp[2] << ":" << temp[3] << "\n";

    return 0;
}