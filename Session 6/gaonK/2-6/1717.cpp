#include <iostream>
#include <vector>
using namespace std;

int find(int x, vector<int> &parent) {
    if (x == parent[x]) return x;
    else return parent[x] = find(parent[x], parent);
}

void Union(int a, int b, vector<int> &parent) {
    a = find(a, parent);
    b = find(b, parent);
    if (a != b) parent[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> parent(n + 1);
    for (int i = 0; i <= n; i++) parent[i] = i;

    for (int i = 0; i < m; i++) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 0) {
            Union(a, b, parent);
        } else if (op == 1) {
            if (find(a, parent) == find(b, parent)) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}