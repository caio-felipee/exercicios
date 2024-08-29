// caio-felipee
//

#include <bits/stdc++.h>

using namespace std;

auto solve()
{
    int n, m, index = 0;
    cin >> n >> m;

    vector<tuple<int, int, int>> vs(n);
    for(auto &[x, y, z] : vs)
    {
        cin >> x >> y;
        z = index++;
    }

    sort(vs.begin(), vs.end());
    for(auto [x, y, z] : vs)
    {
        auto [sx, sy, sz] = vs[z]; 

        if(y != sy)
        {
            cout << "N\n";
            return;
        }
    }

    cout << "Y\n";
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
