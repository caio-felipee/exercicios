#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define all(x) x.begin(), x.end()
#define vin(vt) for (auto &e : vt) cin >> e

auto solve() {
    int n, a;
    cin >> n;
    vector<vi> tree(n + 1);
    for(int i = 2; i <= n; i++) {
        cin >> a;
        tree[a].push_back(i);
    }

    vi desired(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> desired[i];
    }

    vi children_colors(n + 1, desired[1]);
    int ans = 1;
    
    auto dfs = [&](auto &dfs, int dest, int src) -> void {
        if(children_colors[src] != desired[dest]) {
            children_colors[dest] = desired[dest];
            ans++;
        }
        else {
            children_colors[dest] = children_colors[src];
        }

        for(auto &x : tree[dest]) {
            dfs(dfs, x, dest);
        }
    };

    dfs(dfs, 1, 0);

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