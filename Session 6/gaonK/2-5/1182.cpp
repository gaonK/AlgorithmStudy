#include <iostream>
using namespace std;

long long num[20];
int ans = 0;
int N, S;

void go(int pos, long long sum) {
    if (pos == N) {
        if (sum == S) {
            ans++;
        }
        return;
    }

    sum += num[pos];
    go(pos + 1, sum);
    sum -= num[pos];
    go(pos + 1, sum);
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    go(0, 0);
    cout << (S == 0 ? ans - 1 : ans) << '\n';

    return 0;
}