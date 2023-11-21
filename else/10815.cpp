// 숫자 카드

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N = 0;
    int M = 0;
    cin >> N;
    set<int> cards;
    int temp = 0;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        cards.insert(temp);
    }
    cin >> M;
    int numbers[M];
    for (int i = 0; i < M; i++) {
        cin >> temp;
        numbers[i] = temp;
    }
    for (int i = 0; i < M; i++){
        int ith_num = numbers[i];
        bool is_ith_num_in_cards = (cards.find(ith_num) != cards.end());
        if(is_ith_num_in_cards){
            cout << 1 << " ";
        } else {
            cout << 0 << " ";
        }
    }   


        return 0;
}