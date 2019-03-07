#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n && n != 0) {
        vector<long long> histogram(n);
        for (int i = 0; i < n; i++) {
            cin >> histogram[i];
        }

        long long area = 0;
        stack<int> s;
        s.push(0);

        for (int i = 1; i < n; i++) {
            while (!s.empty() && histogram[s.top()] > histogram[i]) {
                int topIndex = s.top();
                s.pop();
                if (s.empty()) {
                    area = max(area, i * histogram[topIndex]);
                } else {
                    area = max(area, (i - s.top() - 1) * histogram[topIndex]);
                }
            }
            s.push(i);
        }

        while (!s.empty()) {
                int topIndex = s.top();
                s.pop();
                if (s.empty()) {
                    area = max(area, n * histogram[topIndex]);
                } else {
                    area = max(area, (n - s.top() - 1) * histogram[topIndex]);
                }
            }
        cout << area << '\n';
    }

    return 0;
}