#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define all(x) x.begin(), x.end()
#define vin(vt) for (auto &e : vt) cin >> e

auto solve() {
    int n, m, a;
    cin >> n >> m;
    vi cat(n + 1);

    for(int i = 1; i <= n; i++) {
        cin >> cat[i];
    }

    vector<vi> tree(n + 1);
    int b;
    for(int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    int ans = 0;
    vector<bool> visited(n + 1, false);
    auto dfs = [&](auto &dfs, int src, int cats) -> void {
        if(cat[src])
            cats++;
        else
            cats = 0;
        
        if(cats > m)
            return;

        if(tree[src].size() > 1 or src == 1) {
            for(auto &x : tree[src]) {
                if(not visited[x]) {
                    visited[x] = true;
                    dfs(dfs, x, cats);
                }
            }
        }
        else {
            ans++;
        }
    };

    visited[1] = true;
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