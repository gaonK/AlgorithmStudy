#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int isVisited[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    isVisited[N] = 1;
    queue<int> q;
    q.push(N);
    while (!q.empty()) {
        int x = q.front();
        q.pop();

        if (x == K) {
            cout << isVisited[x] - 1 << '\n';
            break;
        }

        for (int i = 0; i < 3; i++) {
            int nx;
            if (i == 0) {
                nx = x - 1;
            } else if (i == 1) {
                nx = x + 1;
            } else {
                nx = 2 * x;
            }

            if (0 <= nx && nx <= 100000 && !isVisited[nx]) {
                q.push(nx);
                isVisited[nx] = isVisited[x] + 1;
            } 
        }
    }

    return 0;
}