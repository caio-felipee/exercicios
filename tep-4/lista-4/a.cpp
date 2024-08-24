#include <bits/stdc++.h>

using namespace std;

int main() {
    double sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;

    double ans = ((sy * gx) - (sy * sx)) / (sy + gy);

    cout << fixed << setprecision(7) << ans + sx << "\n";
    return 0;
}
