#include <iostream>
using namespace std;

int N;
int col[16];
bool isVisited[16];
int ans = 0;

bool isPromising(int x) {
    for (int i = 0; i < x; i++) {
        if (col[x] == col[i] || abs(col[x] - col[i]) == abs(x - i)) {
            return false;
        }
    }
    return true;
}

void go(int idx) {
    if (idx == N) {
        ans += 1;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!isVisited[i]) {
            col[idx] = i;
            isVisited[i] = true;
            
            if (isPromising(idx)) {
                go(idx+ 1);
            }

            isVisited[i] = false;
        }
    }
}

int main() {
    cin >> N;
    go(0);
    cout << ans << '\n';
    return 0;
}