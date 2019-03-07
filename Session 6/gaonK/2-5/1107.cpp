#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

bool isBroken[10];

bool checkValid(int num) {
    bool answer = true;

    string s = to_string(num);
    for (int i = 0; i < s.size(); i++) {
        if (isBroken[s[i] - '0']) {
            answer = false;
            break;
        }
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        isBroken[x] = true;
    }

    int tmp = N;
    int cnt = 0;
    int ans = abs(N - 100);
    while (0 <= tmp - cnt || cnt < 500000) {
        if (tmp - cnt >= 0) {
            if (checkValid(tmp - cnt)) {
                ans = min(ans, (int) to_string(tmp - cnt).size() + cnt);
                break;
            }
        } 
        
        if (checkValid(tmp + cnt)) {
            ans = min(ans, (int) to_string(tmp + cnt).size() + cnt);
            break;
        }
        cnt++;
    }
    cout << ans << '\n';

    return 0;
}