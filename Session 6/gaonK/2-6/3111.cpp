#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

// 모듈화 귀찮아서 안 시켰다!!
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string A, T;
    cin >> A >> T;

    int leftIndex = 0;
    int rightIndex = T.size() - 1;

    deque<char> left, right;

    while (leftIndex <= rightIndex) {
        while (leftIndex <= rightIndex) {
            bool hasEqualString = false;
            left.push_back(T[leftIndex++]);

            if (left.size() >= A.size() && left.back() == A.back()) {
                hasEqualString = true;
                for (int i = 0; i < A.size() - 1; i++) {
                    if (left[left.size() - A.size() + i] != A[i]) {
                        hasEqualString = false;
                        break;
                    }
                }
            }
            
            if (hasEqualString) {
                for (int i = 0; i < A.size(); i++) {
                    left.pop_back();
                }
                break;
            }
        }
        
        while (leftIndex <= rightIndex) {
            bool hasEqualString = false;
            right.push_front(T[rightIndex--]);
            
            if (right.size() >= A.size() && right.front() == A.front()) {
                hasEqualString = true;
                for (int i = 1; i < A.size(); i++) {
                    if (right[i] != A[i]) {
                        hasEqualString = false;
                        break;
                    }
                }
            }
            
            if (hasEqualString) {
                for (int i = 0; i < A.size(); i++) {
                    right.pop_front();
                }
                break;
            }
        }
    }

    while (!right.empty()) {
        bool hasEqualString = false;
        left.push_back(right.front());
        right.pop_front();
        
        if (left.size() >= A.size() && left.back() == A.back()) {
            for (int i = 0; i < A.size() - 1; i++) {
                hasEqualString = true;
                if (left[left.size() - A.size() + i] != A[i]) {
                    hasEqualString = false;
                    break;
                }
            }
        }

        if (hasEqualString) {
            for (int i = 0; i < A.size(); i++) {
                left.pop_back();
            }
        }
    }

    for (int i = 0; i < left.size(); i++) {
        cout << left[i];
    }

    return 0;
}