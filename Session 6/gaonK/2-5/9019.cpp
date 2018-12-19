#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

char prevOperation[10001];
int prevNumber[10001];
bool isVisited[10001];
char op[5] = {'D', 'S', 'L', 'R'};

int runD(int n) {
    return (n * 2) % 10000;
}

int runS(int n) {
    return (n + 9999) % 10000;
}

int runL(int n) {
    return (n % 1000) * 10 + n / 1000;
}

int runR(int n) {
    return (n % 10) * 1000 + n / 10;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        for (int i = 0; i < 10000; i++) {
            isVisited[i] = false;
        }

        int n1, n2;
        cin >> n1 >> n2;

        queue<int> q;
        q.push(n1);
        isVisited[n1] = true;
        while (!q.empty()) {
            int x = q.front();
            q.pop();

            if (x == n2) {
                break;
            }

            int next;
            for (int i = 0; i < 4; i++) {
                if (i == 0) next = runD(x);
                if (i == 1) next = runS(x);
                if (i == 2) next = runL(x);
                if (i == 3) next = runR(x);

                if (!isVisited[next]) {
                    q.push(next);
                    isVisited[next] = true;
                    prevOperation[next] = op[i];
                    prevNumber[next] = x;
                }
            }
        }

        int tmp = n2;
        vector<char> ans;
        while (tmp != n1) {
            ans.push_back(prevOperation[tmp]);
            tmp = prevNumber[tmp];
        }
        reverse(ans.begin(), ans.end());
        
        for (char x : ans) {
            cout << x;
        }
        cout << '\n';
    }

    return 0;
}