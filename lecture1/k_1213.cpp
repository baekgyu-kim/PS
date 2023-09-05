// 펠린드롬 만들기

#include <bits/stdc++.h>

using namespace std;

int main() {
    string input;
    cin >> input;
    string result(input.length(), ' ');

    map<char, int> map;
    for (int i = 0; i < input.length(); i++) {
        map[input[i]] += 1;
    }

    int odd_count = 0;
    vector<char> chars;
    char odd;
    for (pair<char, int> pair : map) {
        if(pair.second % 2 != 0){
            odd_count += 1;
            int temp = (pair.second - 1) / 2;
            odd = pair.first;
            for (int i = 0; i < temp; i++) {
                chars.push_back(pair.first);
            }
        }else{
            int temp = pair.second / 2;
            for (int i = 0; i < temp; i++){
                chars.push_back(pair.first);
            }
        }
    }

    sort(chars.begin(), chars.end());

    if(input.length() % 2 != 0){
        if (odd_count != 1) {
            cout << "I'm Sorry Hansoo";
        }else{
            *(result.begin() + ((input.length() - 1) / 2)) = odd;
            for (int i = 0; i < (input.length() - 1) / 2; i++){
                *(result.begin() + i) = chars[i];
                *(result.end() - 1 - i) = chars[i];
            }
        }
    }else{
        if(odd_count != 0){
            cout << "I'm Sorry Hansoo";
        }else{
            for (int i = 0; i < input.length() / 2; i++) {
                *(result.begin() + i) = chars[i];
                *(result.end() - 1 - i) = chars[i];
            }
        }
    }

    cout << result;

    return 0;
}