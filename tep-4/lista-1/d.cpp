
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using ii = pair<int, int>;
using pll = pair<ll, ll>;

auto solve() {
    int ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;

    bx -= ax;
    cx -= ax;

    by -= ay;
    cy -= ay;

    int ans = 1;
    if(bx > 0 and cx > 0)
        ans += min(bx, cx);
    
    if(bx < 0 and cx < 0)
        ans += min(-bx, -cx);

    if(by > 0 and cy > 0)
        ans += min(by, cy);

    if(by < 0 and cy < 0)
        ans += min(-by, -cy);

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();

    return 0;
}
