#include <cstdio>

int main() {
    int E, S, M;
    scanf("%d %d %d", &E, &S, &M);
    int e = 1, s = 1, m = 1;

    int cnt = 1;
    while (!(e == E && s == S && m == M)) {
        e++;
        s++;
        m++;
        cnt++;
        e %= 15;
        if (e == 0) e = 15;
        s %= 28;
        if (s == 0) s = 28;
        m %= 19;
        if (m == 0) m = 19; 
    }
    printf("%d\n", cnt);

    return 0;
}