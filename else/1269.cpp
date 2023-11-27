// 대칭 차집합

#include <bits/stdc++.h>
using namespace std;



int main() {
    int A_num = 0;
    int B_num = 0;
    set<int> result;
    cin >> A_num >> B_num;
    int temp = 0;
    for (int i = 0; i < A_num; i++) {
        cin >> temp;
        result.insert(temp);
    }
    for (int i = 0; i < B_num; i++){
        cin >> temp;
        bool is_num_in_result_set = result.find(temp) != result.end();
        if(is_num_in_result_set){
            result.erase(temp);
        }else{
            result.insert(temp);
        }
    }
    cout << result.size();

    return 0; 
}