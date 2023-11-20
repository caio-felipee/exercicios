#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

using namespace std;

#ifdef DEBUG
#include "../debug/debug.cpp"
#else
#define dbg(...)
#endif

typedef unsigned long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define fst first
#define snd second
#define all(x) x.begin(), x.end()
#define vin(vt) for (auto &e : vt) cin >> e
#define LSOne(S) ((S) & -(S))
#define MSOne(S) (1ull << (63 - __builtin_clzll(S)))

const ll MAX { 200010 };

vector<pll> adj[MAX];

ll prim(ll u, ll N)
{
    set<ll> C;
    C.insert(u);

    priority_queue<pll, vector<pll>, greater<pll>> pq;

    for (auto [v, w] : adj[u])
        pq.push(pll(w, v));

    ll mst = 0;

    while ((ll) C.size() < N)
    {
        ll v, w;

        do {
            w = pq.top().first, v = pq.top().second;
            pq.pop();
        } while (C.count(v));

        mst += w;
        C.insert(v);

        for (auto [s, p] : adj[v])
            pq.push(pll(p, s));
    }

    return mst;
}

bool bfs(ll u, ll n) {
    ll vs = 0;
    vector<bool> visited(n + 1, false);
    visited[u] = true;
    queue<ll> q;
    q.emplace(u);

    while(not q.empty()) {
        vs++;
        ll f = q.front();
        q.pop();

        for(auto [p, w] : adj[f]) {
            if(not visited[p]) {
                visited[p] = true;
                q.emplace(p);
            }
        }
    }

    return vs == n;
}

auto solve() { 
    ll n, m, a, b, w;
    cin >> n >> m;

    for(ll i = 0; i < m; i++) {
        cin >> a >> b >> w;
        adj[a].emplace_back(b, w);
        adj[b].emplace_back(a, w);
    }

    if(not bfs(1, n))
        cout << "IMPOSSIBLE\n";
    else
        cout << prim(1, n) << "\n";
}

int main() {
    ll t = 1;
    //cin >> t;

    while (t--) solve();

    return 0;
}