// caio-felipee
//

#include <bits/stdc++.h>

using namespace std;

auto solve()
{
    int n;
    cin >> n;

    set<pair<int, int>> left;
    map<int, set<int>> vs;
    for(int i = 0; i < n; i++)
    {
        int t;
        cin >> t;

        left.emplace(i, t);
        vs[t].emplace(i);
    }

    int ans = 0;
    while(left.size())
    {
        auto [index, value] = *left.begin();
        left.erase(left.begin());
        vs[value].erase(index);

        for(int i = value - 1; i > 0; i--)
        {
            auto &v = vs[i];

            if(v.empty())
                break;

            auto it = v.lower_bound(index);

            if(it == v.end())
                break;

            index = *it;
            left.extract(make_pair(index, i));
            v.erase(it);
        }

        ++ans;
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
