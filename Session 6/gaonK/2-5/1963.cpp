#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

bool isPrime[100000];
bool isChecked[10000];
int dist[10000];

int change(int n, int i, int j) {
    string s = to_string(n);
    s[i] = (char) j + '0';
    int newN = stoi(s);

    if (newN < 1000 || n == newN) return -1;
    else return newN;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 2; i <= 9999; i++) {
        isPrime[i] = true;
    }

    for (int i = 2; i * i <= 9999; i++) {
        if (isPrime[i] == true) {
            for (int j = i + i; j <= 9999; j += i) {
                isPrime[j] = false;
            }
        }
    }

    int T;
    cin >> T;
    while (T--) {
        for (int i = 1000; i <= 9999; i++) {
            isChecked[i] = false;
            dist[i] = 0;
        }

        int n1, n2;
        cin >> n1 >> n2;
        
        queue<int> q;
        q.push(n1);
        isChecked[n1] = true;
        dist[n1] = 1;

        while (!q.empty()) {
            int x = q.front();
            q.pop();

            if (x == n2) {
                cout << dist[x] - 1 << '\n';
                break;
            }

            for (int i = 0; i < 4; i++) {
                for (int j = 0; j <= 9; j++) {
                    int next = change(x, i, j);

                    if (next != -1) {
                        if (isPrime[next] && !isChecked[next]) {
                            q.push(next);
                            isChecked[next] = true;
                            dist[next] = dist[x] + 1;
                        }
                    }
                }
            }
        }
    }

    return 0;
}