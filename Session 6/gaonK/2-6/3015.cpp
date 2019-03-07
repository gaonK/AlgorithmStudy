#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Height {
    int height = 0;
    int count = 0;

    Height(int h, int c): height(h), count(c) {};
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    long long ans = 0;
    stack<Height> s;
    for (int i = 0; i < n; i++) {
        int count = 1;
        while (!s.empty() && s.top().height <= height[i]) {
            ans += s.top().count;
            if (s.top().height == height[i]) {
                count += s.top().count;
            }
            s.pop();
        }

        if (!s.empty()) ans += 1;
        s.push(Height(height[i], count));
    }

    cout << ans << '\n';

    return 0;
}