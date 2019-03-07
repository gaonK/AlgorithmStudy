#include <iostream>
using namespace std;

bool alphabet[26];
char map[21][21];
int ans = 0;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int R, C;

void dfs(int x, int y, int length) {
    if (length > ans) {
        ans = length;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 <= nx && nx < R && 0 <= ny && ny < C) {
            if (!alphabet[map[nx][ny] - 'A']) {
                alphabet[map[nx][ny] - 'A'] = true;
                dfs(nx, ny, length + 1);
                alphabet[map[nx][ny] - 'A'] = false;
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        cin >> map[i];
    }

    alphabet[map[0][0] - 'A'] = true;
    dfs(0, 0, 1);

    cout << ans << '\n';

    return 0;
}