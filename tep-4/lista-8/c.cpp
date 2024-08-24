#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

auto solve()
{
    ll n;
    cin >> n;

    // value, start
    map<pair<ll, bool>, ll> vs;
    for(ll i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;

        y += x;
        vs[make_pair(x, true)]++;
        vs[make_pair(y, false)]++;
    }

    vector<ll> ans(n + 1);
    ll curr = 0;
    stack<ll> last;
    for(auto [key, amount] : vs)
    {
        auto [x, t] = key;

        if(t)
        {
            if(curr) ans[curr] += x - last.top();

            curr += amount;

            for(ll i = 0; i < amount; i++)
                last.emplace(x);
        }
        else
        {
            ans[curr] += x - last.top();

            for(ll i = 0; i < amount; i++)
                last.pop();

            for(ll i = 0; i < amount; i++)
                last.emplace(x);

            curr -= amount;
        }
    }

    for(ll i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
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
