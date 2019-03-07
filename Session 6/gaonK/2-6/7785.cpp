#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    set<string> s;
    while (n--) {
        string name, op;
        cin >> name >> op;

        if (op == "enter") {
            s.insert(name);
        } else {
            s.erase(s.find(name));
        }
    }

    for (auto i = s.rbegin(); i != s.rend(); i++) {
        cout << *i << '\n';
    }
    return 0;
}