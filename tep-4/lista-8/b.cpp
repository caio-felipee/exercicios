#include <bits/stdc++.h>

using namespace std;

auto solve()
{
    int n;
    cin >> n;

    vector<pair<double, double>> vs;
    for(double i = 0; i < n; i++)
    {
        double l, r;
        cin >> l >> r;

        vs.emplace_back(l, 1);
        vs.emplace_back(r + 1, 0);
    }

    sort(vs.begin(), vs.end());

    long long ans = 0, curr = 0;
    for(auto [v, t] : vs)
    {
        if(t)
            ans += curr++;
        else
            curr--;
    }

    cout << ans << "\n";
}

int main()
{
    int t = 1;
    // cin >> t;
    
    while(t--)
    {
        solve();
    }
}
