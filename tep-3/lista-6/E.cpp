#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;

#ifdef DEBUG
#include "./debug/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()
#define vin(vt) for (auto &e : vt) cin >> e

const ll oo = {LLONG_MAX - 1};

vl bfs(ll n, ll s, vector<vector<pair<ll, ll>>> &graph) {
    vl dist(n + 1, oo);
    queue<ll> q;
    q.emplace(s);
    dist[s] = 0;

    while(not q.empty()) {
        auto f = q.front();
        q.pop();

        for(auto [p, w] : graph[f]) {
            if(dist[p] == oo) {
                dist[p] = dist[f] + w;
                q.emplace(p);
            }
        }
    }

    return dist;
}

auto solve() {
    ll n, a, b, c, q, k;
    cin >> n;

    vector<vector<pair<ll, ll>>> tree(n + 1);
    for(ll i = 0; i < n - 1; i++) {
        cin >> a >> b >> c;
        tree[a].emplace_back(b, c);
        tree[b].emplace_back(a, c);
    }

    cin >> q >> k;
    vl dist = bfs(n, k, tree);
    dbg(dist);

    while(q--) {
        cin >> a >> b;
        cout << dist[a] + dist[b] << "\n";
    }
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