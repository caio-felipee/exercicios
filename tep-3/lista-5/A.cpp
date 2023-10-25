#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
using pll = pair<ll, ll>;
using edge = tuple<ll, ll, ll>;

const ll MAX { 100010 }, oo { (ll)1e12 };
vector<pll> adj[MAX];
bitset<MAX> processed;

pair<vector<ll>, vector<ll>> dijkstra(ll s, ll N)
{
    vector<ll> dist(N + 1, oo), pred(N + 1, oo);
    dist[s] = 0;
    pred[s] = s;

    processed.reset();

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.emplace(0, s);

    while (not pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (processed[u])
            continue;

        processed[u] = true;

        for (auto [v, w] : adj[u])
        {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pred[v] = u;
                pq.emplace(dist[v], v);
            }
        }
    }

    return { dist, pred };
}

vector<pll> path(ll s, ll u, const vector<ll>& pred)
{
    vector<pll> p;
    ll v = u;

    do {
        p.push_back(pll(pred[v], v));
        v = pred[v];
    } while (v != s);

    reverse(p.begin(), p.end());

    return p;
}

int main()
{
    ll n, m, a, b, w;
    cin >> n >> m;

    for(ll i = 0; i < m; i++) {
        cin >> a >> b >> w;
        adj[a].emplace_back(b, w);
        adj[b].emplace_back(a, w);
    }

    auto [dist, pred] = dijkstra(1, n);

    if(dist[n] == oo) {
        cout << -1 << "\n";
        return 0;
    }

    auto p = path(1, n, pred);

    for(auto &[x, y] : p)
        cout << x << " ";
    cout << n << "\n";
} 
