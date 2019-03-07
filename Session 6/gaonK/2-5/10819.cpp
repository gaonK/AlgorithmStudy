#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int calculate(vector<int> v) {
    int ans = 0;
    int size = v.size();
    for (int i = 1; i < size; i++) {
        ans += abs(v[i] - v[i - 1]);
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> v;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    int ans = 0;
    do {
        int tmp = calculate(v);
        ans = max(ans, tmp);
    } while (next_permutation(v.begin(), v.end()));

    cout << ans << '\n';

    return 0;
}