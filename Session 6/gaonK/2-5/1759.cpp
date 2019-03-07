#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> v;
vector<char> input;
int L, C;

void go(int idx) {
    if (idx == C) {
        if (v.size() == L) {
            int vowelCount = 0;
            int consonantCount = 0;
            
            for (int i = 0; i < L; i++) {
                if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u') {
                    vowelCount++;
                } else {
                    consonantCount++;
                }
            }

            if (vowelCount >= 1 && consonantCount >= 2) {
                for (char x : v) {
                    cout << x;
                }
                cout << '\n';
            }
        }
        return;
    } 

    v.push_back(input[idx]);
    go(idx + 1);
    v.pop_back();
    go(idx + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> L >> C;

    for (int i = 0; i < C; i++) {
        char x;
        cin >> x;
        input.push_back(x);
    }
    sort(input.begin(), input.end());

    go(0);

    return 0;
}