#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int W[11][11];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> W[i][j];
        }
    }

    vector<int> v;
    for (int i = 1; i <= N; i++) {
        v.push_back(i);
    }

    int ans = 100000000;

    do {
        if (v[0] != 1) {
            break;
        }
        
        int tmp = 0;
        bool flag = true;
        for (int i = 0; i < N; i++) {
            if (W[v[i]][v[(i + 1) % N]]) {
                tmp += W[v[i]][v[(i + 1) % N]];
            } else {
                flag = false;
                break;
            }
        }

        if (flag) {
            ans = min(ans, tmp);
        }

    } while (next_permutation(v.begin(), v.end()));

    cout << ans << '\n';

    return 0;
}