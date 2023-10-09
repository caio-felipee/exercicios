#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define all(x) x.begin(), x.end()
#define vin(vt) for (auto &e : vt) cin >> e

bitset<1001> visited;
vi bfs(vector<vi> &graph, int src) {
    vi ans;
    vi path(graph.size() + 1, 0);
    queue<int> q;
    q.emplace(src);
    visited.reset();
    visited.set(src, 1);

    while(not q.empty()) {
        int f = q.front();
        q.pop();

        for(auto &x : graph[f]) {
            if(not visited[x]) {
                visited.set(x, 1);
                path[x] = f;
                q.emplace(x);
            }
            else if(x == src){
                int curr = f;
                while(curr != src) {
                    ans.push_back(curr);
                    curr = path[curr];
                }
                ans.push_back(src);

                return ans;
            }
        }
    }

    ans.clear();
    return ans;
}

auto solve() {
    int n, m, a, b;
    cin >> n >> m;

    vector<vi> graph(n + 1);
    for(int i = 1; i <= m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
    }

    vi ans, tmp;
    for(int i = 1; i <= n; i++) {
        tmp = bfs(graph, i);

        if(not ans.size() or (tmp.size() and tmp.size() < ans.size()))
            ans = tmp;
    }

    cout << (ans.size() ? (int)ans.size() : -1) << "\n";

    for(auto &x : ans) 
        cout << x << "\n";
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