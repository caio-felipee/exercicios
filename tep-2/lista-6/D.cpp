#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

auto solve() {
    int a, b, c;

    cin >> a >> b >> c;

    vi v(a * b * c + 1);

    for(int i = 1; i < v.size(); i++) {
        for(int j = i; j < v.size(); j += i) {
            v[j]++;
        }
    }

    ll ans = 0;

    for(int i = 1; i <= a; i++) {
        for(int j = 1; j <= b; j++) {
            for(int k = 1; k <= c; k++) {
                ans += v[i * j * k];
            }
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}