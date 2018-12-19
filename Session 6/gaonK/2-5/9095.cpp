#include <iostream>
using namespace std;

int arr[12];

int main() {
    int T;
    cin >> T;

    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    for (int i = 4; i <= 11; i++) {
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
    }

    while (T--) {
        int N;
        cin >> N;
        cout << arr[N] << '\n';
    }

    return 0;
}