// caio-felipee
//

#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;
using vii = vector<ii>;

auto prim(int N, int src, vector<vii> &graph)
{
    vector<vii> res(N + 1);
    set<int> C;
    C.emplace(src);

    priority_queue<tuple<int, int, int>> pq;
    for(auto [v, w] : graph[src]) pq.emplace(w, v, src);

    while(C.size() < N)
    {
        int v, x, w;

        do
        {
            auto [weight, a, b] = pq.top();
            pq.pop();

            w = weight, v = a, x = b;
        }
        while(C.count(v));

        res[v].emplace_back(x, w);
        res[x].emplace_back(v, w);
        C.emplace(v);

        for(auto [s, p] : graph[v]) pq.emplace(p, s, v);
    }

    return res;
}

auto solve()
{
    int n, m, q;
    cin >> n >> m >> q;

    vector<vii> graph(n + 1);
    for(int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;

        graph[a].emplace_back(b, w);
        graph[b].emplace_back(a, w);
    }
    
    // we need something like a MST
    // but it needs the hst weights
    vector<vii> res = prim(n, 1, graph);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;

    while(t--)
    {
        solve();
    }
}
