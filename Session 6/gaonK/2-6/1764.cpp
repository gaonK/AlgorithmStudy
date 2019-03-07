#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    set<string> s;
    vector<string> ans;
    cin >> n >> m;
    while (n--) {
        string name;
        cin >> name;
        s.insert(name);
    }
    while (m--) {
        string name;
        cin >> name;
        if (s.count(name)) {
            ans.push_back(name);
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto &item : ans) {
        cout << item << '\n';
    }
    
    return 0;
}