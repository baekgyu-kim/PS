#include <bits/stdc++.h>
using namespace std;

int M = 0;
int s = 0;
char operation[10];
int x = 0;

void calculate(char* operation, int param) {
    if (strcmp(operation, "add") == 0) {
        s = s | (1 << param);
    } else if (strcmp(operation, "remove") == 0) {
        s = s & ~(1 << param);

    } else if (strcmp(operation, "check") == 0) {
        if ((s & (1 << param)) == (1 << param)) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    } else if (strcmp(operation, "toggle") == 0) {
        s = s ^ (1 << param);
    } else if (strcmp(operation, "all") == 0) {
        s = 2097150;
    } else if (strcmp(operation, "empty") == 0) {
        s = 0;

    } else {
        cout << "오류!!"
             << "\n";
    }
}


int main() {
    cin >> M;
    string bufferflush;
    getline(cin, bufferflush);
    for (int i = 0; i < M; i++) {
        scanf("%s", operation);
        if (strcmp(operation,"all") == 0) {
            calculate("all", 0);
        } else if (strcmp(operation, "empty") == 0) {
            calculate("empty", 0);
        }
        scanf("%d", &x);
        calculate(operation, x);
    }
    return 0;
}