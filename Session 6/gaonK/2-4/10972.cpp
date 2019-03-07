#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    if (next_permutation(v.begin(), v.end())) {
        for (int i = 0; i < N; i++) {
            cout << v[i] << ' ';
        }
        cout << '\n';
    } else {
        cout << "-1\n";
    }

    return 0;
}