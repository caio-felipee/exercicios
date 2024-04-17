

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using ii = pair<int, int>;
using pll = pair<ll, ll>;
using vii = vector<ii>;

vii dir4 = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

auto dist(ii sp, ii fp = ii{0, 0})
{
    return abs(sp.first - fp.first) + abs(sp.second - fp.second);
}

auto f(int n, vii points)
{
    unordered_map<int, bool> visited;
     
    ii last = {0, 0};
    int ans = 0, i = 0; 
    while(i++ < n)
    {
        int d = INT_MAX, clst = 0;

        for(int x = 0; x < n; x++)
        {
            if(visited[x] or dist(points[x], last) > d)
                continue;

            d = dist(points[x], last);
            clst = x;
        }

        visited[clst] = true;
        ans += d;
        last = points[clst];
    }

    return ans + dist(last);
}

auto solve() {
    int n;
    cin >> n;

    vii vs(n);
    for(int i = 0; i < n; i++)
        cin >> vs[i].first >> vs[i].second;

    auto ans = f(n, vs);

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();

    return 0;
}
