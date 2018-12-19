#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    while (cin >> k && k != 0) {
        vector<int> v;
        for (int i = 0; i < k; i++) {
            int x;
            cin >> x;
            v.push_back(x);
        }

        vector<int> lotto;
        for (int i = 0; i < 6; i++) {
            lotto.push_back(0);
        }
        for (int i = 0; i < k - 6; i++) {
            lotto.push_back(1);
        }
        
        do {
            for (int i = 0; i < k; i++) {
                if (!lotto[i]) {
                    cout << v[i] << ' ';
                }
            }
            cout << '\n';
        } while (next_permutation(lotto.begin(), lotto.end()));
        cout << '\n';
    }

    return 0;
}