#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    double x, y, c;
    scanf("%lf %lf %lf", &x, &y, &c);
    
    double left = 0;
    double right = min(x, y);
    double mid;
    while (abs(right - left) >= 1e-6) {
        mid = (left + right) / 2.0;
        double d = mid;
        double h1 = sqrt(x * x - d * d);
        double h2 = sqrt(y * y - d * d);
        double h = (h1 * h2) / (h1 + h2);

        if (h > c) {
            left = mid;
        } else {
            right = mid;
        }
    }
    printf("%.3lf\n", mid);

    return 0;
}