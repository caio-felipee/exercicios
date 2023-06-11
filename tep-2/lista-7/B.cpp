#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define all(x) x.begin(), x.end()
#define vin(vt) for (auto &e : vt) cin >> e
#define LSOne(S) ((S) & -(S))
#define MSOne(S) (1ull << (63 - __builtin_clzll(S)))

auto solve() {
    ll n;

    cin >> n;

    vector<ll> val(n + 1, 0);

    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j += i)
            val[j]++;

    ll ans = 0;

    for(int i = 1; i <= n; i++) {
        ans += (i * val[i]);
        // cout << "f(" << i << ") = " << val[i] << "\n";
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