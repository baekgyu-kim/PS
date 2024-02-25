#include <bits/stdc++.h>
using namespace std;
int N = 0;
int A[1000004] = {0};
int NGE[1000004] = {0};
stack<int> st;



int main() {
    cin >> N;
    int a = 0;
    for (int i = 0; i < N; i++) {
        cin >> a;
        A[i] = a;
    }
    st.push(A[N - 1]);
    NGE[N - 1] = -1;
    for (int i = N - 2; i >= 0; i--) {
        while(st.top() <= A[i]){
            st.pop();
            if(st.size() == 0){
                break;
            }
        }
        if(st.size() == 0){
            NGE[i] = -1;
        }else{
            NGE[i] = st.top();
        }
        st.push(A[i]);
    }
    for (int i = 0; i < N; i++) {
        cout << NGE[i] << " ";
    }
    return 0;
}