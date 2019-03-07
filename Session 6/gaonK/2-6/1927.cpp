#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    priority_queue<int, vector<int>, greater<int> > pq;

    cin >> n;

    while (n--) {
        int x;
        cin >> x;

        if (x == 0) {
            cout << (pq.empty() ? 0 : pq.top()) << '\n';
            if (!pq.empty()) pq.pop();
        } else {
            pq.push(x);
        }
    }

    return 0;
}