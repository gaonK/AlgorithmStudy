#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> v;

    for (int i = 1; i <= N; i++) {
        v.push_back(i);
        cout << i << ' ';
    }
    cout << '\n';

    while (next_permutation(v.begin(), v.end())) {
        for (int i = 0; i < N; i++) {
            cout << v[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}