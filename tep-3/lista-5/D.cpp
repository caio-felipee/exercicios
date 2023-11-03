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

vector<vi> bfs_01(int n, int m, int sx, int sy, vector<string> &grid) {
    vector<vi> dist(n, vi(m, oo));

    deque<ii> q;
    q.emplace_front(sx, sy);
    dist[sx][sy] = 0;

    while(not q.empty()) {
        auto [x, y] = q.front();
        q.pop_front();

        for(auto [dx, dy] : dir4) {
            int xi = dx + x, yi = dy + y;

            if(xi < 0 or xi >= n or yi < 0 or yi >= m)
                continue;
            
            int p = (int)(grid[x][y] != grid[xi][yi]);

            if(dist[xi][yi] > dist[x][y] + p) {
                dist[xi][yi] = dist[x][y] + p;
                p ? q.emplace_back(xi, yi) : q.emplace_front(xi, yi);
            } 
        }
    }

    return dist;
}

auto solve() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    vin(grid);

    vector<vi> dist = bfs_01(n, m, 0, 0, grid);
    cout << dist[n - 1][m - 1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}