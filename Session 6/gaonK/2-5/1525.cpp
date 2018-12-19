#include <iostream>
#include <queue>
#include <map>
#include <string>
using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    for (int i = 0; i < 9; i++) {
        string x;
        cin >> x;
        if (x == "0") {
            x = "9";
        }
        s.append(x);
    }

    queue<int> q;
    map<int, int> dist;
    
    int start = stoi(s);
    q.push(start);
    dist[start] = 0;
    
    while (!q.empty()) {
        int nowNum = q.front();
        q.pop();
        string now = to_string(nowNum);

        if (now == "123456789") {
            cout << dist[123456789] << '\n';
            return 0;
        }

        int z = now.find('9');
        int x = z / 3;
        int y = z % 3;
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx && nx < 3 && 0 <= ny && ny < 3) {
                string next = now;
                swap(next[3 * x + y], next[3 * nx + ny]);
                int nextNum = stoi(next);
                if (dist.count(nextNum) == 0) {
                    dist[nextNum] = dist[nowNum] + 1;
                    q.push(nextNum);
                }
            }
        }
    }
    cout << -1 << '\n';

    return 0;
}