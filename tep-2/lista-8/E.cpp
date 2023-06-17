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
    ll n, m;

    cin >> n >> m;

    set<int> rows, columns;
    
    ll val = n * n;
    int r, c;

    while(m--) {
        cin >> r >> c;

        if(not rows.count(r)) {
            val -= (n - columns.size());
            rows.insert(r);
        }
        if(not columns.count(c)) {
            val -= (n - rows.size());
            columns.insert(c);
        }

        cout << val << " ";
    }

    cout << "\n";
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