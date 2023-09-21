#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define all(x) x.begin(), x.end()
#define vin(vt) for (auto &e : vt) cin >> e

const vii dir8{ {1,0}, {-1,0}, {0,1}, {0,-1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1} };

auto solve() {
    int bx, by, ex, ey;
    char ca, cb;

    cin >> ca >> by >> cb >> ey;

    bx = ca - 'a' + 1;
    ex = cb - 'a' + 1;

    vector<vi> dist(9, vi(9, 10000));
    vector<vii> path(9, vii(9));
    queue<ii> q;
    q.emplace(bx, by);
    dist[bx][by] = 0;
    while(not q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for(auto &[dx, dy] : dir8) {
            int xi = x + dx;
            int yi = y + dy;

            if(xi < 0 or xi > 8 or yi < 0 or yi > 8)
                continue;
            
            if(dist[xi][yi] == 10000)
                q.emplace(xi, yi);

            if(dist[xi][yi] > dist[x][y] + 1) {
                dist[xi][yi] = dist[x][y] + 1;
                path[xi][yi] = ii(x, y);
            }
        }
    }

    map<ii, string> mp;
    mp[ii(1, 0)] = "R";
    mp[ii(-1, 0)] = "L";
    mp[ii(0, 1)] = "U";
    mp[ii(0, -1)] = "D";
    mp[ii(1, 1)] = "RU";
    mp[ii(-1, -1)] = "LD";
    mp[ii(1, -1)] = "RD";
    mp[ii(-1, 1)] = "LU";

    vector<string> ans;
    while(bx != ex or by != ey) {
        auto [dx, dy] = path[ex][ey];

        ans.push_back(mp[ii(ex - dx, ey - dy)]);
        ex = dx;
        ey = dy;
    }

    reverse(all(ans));

    cout << ans.size() << "\n";
    for(auto &x : ans) {
        cout << x << "\n";
    }
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