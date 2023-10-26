#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define all(x) x.begin(), x.end()
#define vin(vt) for (auto &e : vt) cin >> e

const vii dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int oo { (int)1e7 };

vector<vi> bfs(vector<string> &grid, int x, int y, int n, int m) {
    vector<vi> dist(n, vi(m, oo));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    deque<ii> q;
    q.emplace_back(x, y);
    dist[x][y] = 0;

    while(not q.empty()) {
        auto [fx, fy] = q.front();
        q.pop_front();

        if(visited[fx][fy])
            continue;
        
        visited[fx][fy] = true;

        for(auto [dx, dy] : dir4) {
            int xi = fx + dx, yi = fy + dy;

            if(xi >= n or xi < 0 or yi >= m or yi < 0 or grid[xi][yi] == '#' or dist[xi][yi] <= dist[fx][fy])
                continue;
            
            // cout << xi << " " << yi <<  " " << dist[fx][fy] << "\n";
            dist[xi][yi] = dist[fx][fy];
            q.emplace_front(xi, yi);            
        }

        for(int dx = max(0, fx - 2); dx <= min(fx + 2, n - 1); dx++) {
            for(int dy = max(0, fy - 2); dy <= min(fy + 2, m - 1); dy++) {
                if(grid[dx][dy] == '#' or dist[dx][dy] <= dist[fx][fy] + 1)
                    continue;
                
                dist[dx][dy] = dist[fx][fy] + 1;
                q.emplace_back(dx, dy);
            }
        }
    }

    return dist;
}

auto solve() {
    int n, m, sx, sy, ex, ey;
    cin >> n >> m >> sx >> sy >> ex >> ey;

    vector<string> vs(n);
    for(int i = 0; i < n; i++) {
        cin >> vs[i];
    }

    sx--; sy--; ex--; ey--;

    vector<vi> dist = bfs(vs, sx, sy, n, m);

    cout << (dist[ex][ey] == oo ? -1 : dist[ex][ey]) << "\n";
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