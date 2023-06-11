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

ll get_div(ll n) {
    unordered_set<ll> values;
    values.insert(1);

    for(ll i = 2; i * i <= n; i++) {
        cout << i << "\n";
        if(n % i == 0) {
            values.insert(i);
            cout << "add " << i << "\n";
            n /= i;

            while(n % i == 0)
                n /= i;
        }
    }

    values.insert(n);
    
    return values.size();
}

auto solve() {
    ll a, b;

    cin >> a >> b;

    ll val = gcd(a, b);

    cout << get_div(val) << "\n";
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