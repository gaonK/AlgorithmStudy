#include <iostream>
#include <algorithm>
using namespace std;

int arr[5000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    nth_element(arr, arr + K - 1, arr + N);
    cout << arr[K - 1] << '\n';

    return 0;
}