#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#ifdef DEBUG
#include "./debug/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()
#define vin(vt) for (auto &e : vt) cin >> e

void bfs(int s, vector<vi> &graph, vi &visited) {
  queue<int> q;
  q.emplace(s);
  visited[s] = 1;

  while(not q.empty()) {
    int f = q.front();
    q.pop();

    for(auto &x : graph[f]) {
      if(not visited[x]) {
        visited[x] = visited[f] + 1;
        q.emplace(x);
      }
    }
  }
}

auto solve() {
    int n, a, b;
    cin >> n;

    vector<vi> graph(n + 1);
    for(int i = 0; i < n - 1; i++) {
      cin >> a >> b;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }

    vi fvisit(n + 1, 0), svisit(n + 1, 0);
    bfs(1, graph, fvisit);
    bfs(n, graph, svisit);

    dbg(fvisit);
    dbg(svisit);

    int s = 0, f = 0;
    for(int i = 1; i <= n; i++) {
      (fvisit[i] <= svisit[i]) ? f++ : s++;
    }

    dbg(f, s);

    cout << (f > s ? "Fennec" : "Snuke") << "\n";
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