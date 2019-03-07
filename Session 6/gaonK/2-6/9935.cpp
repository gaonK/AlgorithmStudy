#include <iostream>
using namespace std;

char stack[1000001];

bool checkIfStackHasBomb(string bomb, int top) {
    bool flag = true;
    for (int i = 0; i < bomb.size() - 1; i++) {
        if (stack[top - bomb.size() + i] != bomb[i]) {
            flag = false;
        }
    }
    return flag;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s, bomb;
    cin >> s >> bomb;
    int index = 0;
    int top = 0;
    
    while (index < s.size()) {
        stack[top++] = s[index++];
        if (top >= bomb.size() && stack[top - 1] == bomb.back()) {
            if (checkIfStackHasBomb(bomb, top)) {
                top -= bomb.size();
            }
        } 
    }

    for (int i = 0; i < top; i++) {
        cout << stack[i];
    }
    
    if (top == 0) {
        cout << "FRULA";
    }

    return 0;
}