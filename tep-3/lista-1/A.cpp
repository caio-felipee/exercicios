#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define all(x) x.begin(), x.end()
#define vin(vt) for (auto &e : vt) cin >> e

auto solve() {
    int n, m, a, b;
    cin >> n >> m;
    vi elevation(n + 1);

    for(int i = 1; i <= n; i++) {
        cin >> elevation[i];
    }

    vi good(n + 1, 1);
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        if(elevation[a] >= elevation[b])
            good[b] = 0;
        
        if(elevation[b] >= elevation[a])
            good[a] = 0;
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += good[i];
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