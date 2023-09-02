#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define all(x) x.begin(), x.end()
#define vin(vt) for (auto &e : vt) cin >> e

const int MAX = 1e6;

auto solve() {
    int n, m, a, b;
    cin >> n >> m;
    vector<vi> graph(n + 1);

    for(int i = 1; i <= m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> dist(n + 1, MAX);
    queue<int> q;

    q.push(1);
    dist[1] = 0;

    while(not q.empty()) {
        int f = q.front();
        q.pop();
        for(auto &x : graph[f]) {
            if(dist[x] == MAX) {
                dist[x] = dist[f] + 1;
                q.push(x);
            }
        }
    }

    return (dist[n] <= 2 ? "POSSIBLE" : "IMPOSSIBLE");
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    //cin >> t;

    while (t--) {
        cout << solve() << "\n";
    }

    return 0;
}