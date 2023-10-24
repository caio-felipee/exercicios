#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define all(x) x.begin(), x.end()

const int MAX { 100010 };
const int oo { 1000000010 };

vector<int> dijkstra(vector<vii> &adj, int s, int N)
{

    vector<int> dist(N + 1, oo);
    dist[s] = 0;

    set<ii> U;
    U.emplace(0, s);

    while (not U.empty())
    {
        ii du = *U.begin();
        int d = du.first, u = du.second;
        U.erase(U.begin());

        for (ii vw : adj[u])
        {
            int v = vw.first, w = vw.second;
            if (dist[v] > d + w)
            {
                if (U.count(ii(dist[v], v)))
                    U.erase(ii(dist[v], v));

                dist[v] = d + w;
                U.emplace(dist[v], v);
            }
        }
    }

    return dist;
}
int solve() {
    int n, m, s, t, a, b, w;
    cin >> n >> m >> s >> t;

    vector<vii> graph(n);
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        graph[a].emplace_back(b, w);
        graph[b].emplace_back(a, w);
    }

    vi dist = dijkstra(graph, s, n);

    return dist[t] != oo ? dist[t] : -1;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

   for(int i = 1; i <= t; i++) {
        int ans = solve();
        cout << "Case #" << i << ": ";

        if(ans == -1)
            cout << "unreachable";
        else
            cout << ans;
        cout << "\n";
    }

    return 0;
}