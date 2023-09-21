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

    vector<vi> graph(n + 1);
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int ans = 0, tmp = 1;
    auto dfs = [&](auto &dfs, vector<bool> &visited, int src) -> void {
        int size = 0;

        for(auto &x : graph[src]) {
            if(graph[x].size()) {
                size++;
            
                if(not visited[x]) {
                    visited[x] = true;
                    dfs(dfs, visited, x);
                }
            }
        }

        if(size == 1) {
            graph[src].clear();
            tmp++;
        } 
    };

    while(tmp > 0) {
        tmp = 0;
        vector<bool> visited(n + 1, false);

        for(int i = 1; i <= n; i++) {
            if(not visited[i] and graph[i].size()) {
                visited[i] = true;
                dfs(dfs, visited, i);
            }
        }

        if(tmp)
            ans++;        
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