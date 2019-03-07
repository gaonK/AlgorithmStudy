#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

bool isVisited[201][201];
bool ans[201];

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    
    int total = C;
    queue<pair<int, int>> q;

    q.push(make_pair(0, 0));
    isVisited[0][0] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        int z = total - x - y;

        if (x == 0) {
            ans[z] = true;
        }

        int nx, ny;
        for (int i = 0; i < 6; i++) {
            // z -> x  
            if (i == 0) {
                nx = min(A, x + z);
                ny = y;
            }
            // z -> y
            if (i == 1) {
                nx = x;
                ny = min(B, y + z);
            }
            // x -> y
            if (i == 2) {
                nx = max(0, x + y - B);
                ny = min(B, x + y);
            }
            // x -> z
            if (i == 3) {
                nx = max(0, x + z - C);
                ny = y;
            }
            // y -> x
            if (i == 4) {
                nx = min(A, x + y);
                ny = max(0, x + y - A);
            }
            // y -> z
            if (i == 5) {
                nx = x;
                ny = max(0, x + z - C);
            }

            if (!isVisited[nx][ny]) {
                q.push(make_pair(nx, ny));
                isVisited[nx][ny] = true;
            }
        }
    }

    for (int i = 0; i <= C; i++) {
        if (ans[i]) {
            cout << i << ' ';
        }
    }
    cout << '\n'; 

    return 0;
}