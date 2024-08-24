
#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using ii = pair<int, int>;
using pll = pair<ll, ll>;

auto solve() {
    int n, k;
    cin >> n >> k;

    vector<ii> vs(n);
    for(int i = 0; i < n; i++)
        cin >> vs[i].first >> vs[i].second;

    double dist = 0;
    for(int i = 1; i < n; i++)
    {
        auto [xi, yi] = vs[i - 1];
        auto [xj, yj] = vs[i];

        dist += hypot((xi - xj), (yi - yj));
    }
    
    double x = dist / 50;
    x *= k;
    cout.precision(7);
    cout << setprecision(7) << x << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;

    while(t--)
        solve();

    return 0;
}
