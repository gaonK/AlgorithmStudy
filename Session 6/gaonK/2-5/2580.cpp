#include <iostream>
using namespace std;

int board[10][10];
bool check1[10][10];
bool check2[10][10];
bool check3[10][10];

bool isPrinted = false;

void go(int z) {
    if (isPrinted) {
        return;
    }

    if (z == 81) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
        isPrinted = true;
    }

    int x = z / 9;
    int y = z % 9;

    if (board[x][y]) {
        go(z + 1);
    } else {
        for (int i = 1; i <= 9; i++) {
            if (!check1[x][i] && !check2[y][i] && !check3[(x / 3) * 3 + (y / 3)][i]) {
                check1[x][i] = true;
                check2[y][i] = true;
                check3[(x / 3) * 3 + (y / 3)][i] = true;
                board[x][y] = i;
                go(z + 1);
                board[x][y] = 0;
                check1[x][i] = false;
                check2[y][i] = false;
                check3[(x / 3) * 3 + (y / 3)][i] = false;
            }
        }
    }
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
            if (board[i][j]) {
                check1[i][board[i][j]] = true;
                check2[j][board[i][j]] = true;
                check3[(i / 3) * 3 + (j / 3)][board[i][j]] = true;
            }
        }
    }
    go(0);

    return 0;
}