#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define all(x) x.begin(), x.end()
#define vin(vt) for (auto &e : vt) cin >> e

const vector<ii> dirs = {{1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

auto solve() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    vin(grid);

    int mv = min(n + 1, m + 1);
    vi ans(mv, 0);
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int size = 0;

    auto dfs = [&](auto &dfs, int x, int y) -> void {
        size++;

        for(auto [dx, dy] : dirs) {
            int xi = x + dx;
            int yi = y + dy;

            if(xi < 0 or yi < 0 or xi >= n or yi >= m)
                continue;
            
            if(grid[xi][yi] == '#' and not visited[xi][yi]) {
                visited[xi][yi] = true;
                dfs(dfs, xi, yi); 
            }
        }
    };

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(not visited[i][j] && grid[i][j] == '#') {
                size = 0;
                visited[i][j] = true;
                dfs(dfs, i, j);
                ans[size/4]++;
            }
        }
    }

    for(int i = 1; i < mv; i++) {
        cout << ans[i] << " ";
    }

    cout << "\n";
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