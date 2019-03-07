#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int ans = 0;
    while (N--) {
        string s;
        cin >> s;
        if (s == "add") {
            int x;
            cin >> x;
            ans = ans | (1 << x);
        } else if (s == "remove") {
            int x;
            cin >> x;
            ans = ans & ~(1 << x);
        } else if (s == "check") {
            int x;
            cin >> x;
            if (ans & (1 << x)) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        } else if (s == "toggle") {
            int x;
            cin >> x;
            ans = ans ^ (1 << x);
        } else if (s == "all") {
            for (int i = 1; i <= 20; i++) {
                ans = ans | (1 << i);
            }
        } else if (s == "empty") {
            ans = 0;
        }
    }

    return 0;
}