// caio-felipee
//

#include <bits/stdc++.h>

using namespace std;

auto solve()
{
    int n, gx, gy;
    cin >> n >> gx >> gy;

    int bound = (1 << n);
    vector<pair<int, int>> vs = {{0, 0}, {0, bound}, {bound, bound}, {bound, 0}};

    int st = (1 << (n - 1));
    map<pair<int, int>, int> dist;
    
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> q;
    q.emplace(0, gx, gy);
    int ans = INT_MAX;
    while(q.size())
    {
        auto [d, x, y] = q.top();
        q.pop();

        if(x == st and y == st)
        {
            ans = min(ans, d);
            break;
        }

        for(auto &[dx, dy] : vs)
        {
            int nx = (2 * x) - dx, ny = (2 * y) - dy;

            if(nx > bound or ny > bound or nx < 0 or ny < 0)
                continue;

            auto it = dist.find(make_pair(nx, ny));
            
            if(it == dist.end() or it->second > d + 1)
            {
                auto &dst = dist[make_pair(nx, ny)] = d + 1;

                q.emplace(dst, nx, ny);
            }
        }
    }

    cout << ans << "\n";
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
