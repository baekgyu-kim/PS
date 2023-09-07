// 좋은 단어

#include <bits/stdc++.h>

using namespace std;

int is_good_word(string word) {
    stack<char> stack;
    stack.push(word[0]);
    for (int i = 1; i < word.size(); i++) {
        if (!stack.empty() && word[i] == stack.top()) {
            stack.pop();
            continue;
        }else{
            stack.push(word[i]);
        }
    }
    if(stack.empty()){
        return 1;
    }else{
        return 0;
    }
}

int main() {
    int N;
    cin >> N;
    int result = 0;
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        if(is_good_word(word)){
            result += 1;
        }
    }

    cout << result;
    return 0;
}