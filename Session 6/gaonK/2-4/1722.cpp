#include <iostream>
using namespace std;

long long factorial[21];
bool isChecked[21];

int main() {
    int N;
    cin >> N;

    factorial[0] = 1;
    factorial[1] = 1;
    for (int i = 2; i <= N; i++) {
        factorial[i] = factorial[i - 1] * i;
    }

    int question;
    cin >> question;

    if (question == 1) {
        long long k;
        cin >> k;

        for (int i = 1; i <= N; i++) {
            int cnt;
            cnt = k / factorial[N - i];
            if (k % factorial[N - i] == 0) {
                cnt--;
            }
            k -= cnt * factorial[N - i];
            
            for (int j = 1; j <= N; j++) {
                if (!isChecked[j]) {
                    if (cnt == 0) {
                        isChecked[j] = true;
                        cout << j << ' ';
                        break;
                    } else {
                        cnt--;
                    }
                }
            }
        }

    } else if (question == 2) {
        long long ans = 1;
        int num[N];
        for (int i = 0; i < N; i++) {
            cin >> num[i];
        }

        for (int i = 0; i < N - 1; i++) {
            isChecked[num[i]] = true;
            for (int j = 1; j < num[i]; j++) {
                if (!isChecked[j]) {
                    ans += factorial[N - i - 1];
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}