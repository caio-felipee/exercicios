#include <bits/stdc++.h>

using namespace std;

using ll = long long;

auto solve()
{
    ll n, d;
    cin >> n >> d;

    vector<tuple<ll, ll, ll>> vs;
    for(ll i = 0; i < n; i++)
    {
        ll l, r;
        cin >> l >> r;

        // 1 é final
        vs.emplace_back(l, i, 0);
        vs.emplace_back(r, i, 1);
    }

    sort(vs.begin(), vs.end());

    ll ans = 0, cover = LLONG_MIN;
    vector<bool> broken(n + 1);
    queue<ll> hist;
    for(auto [x, index, end] : vs)
    {
        if(broken[index]) continue;
        
        if(cover >= x)
        {
            broken[index] = true;
        }
        else if(end)
        {
            ++ans;
            cover = x + d - 1;
            broken[index] = true;

            while(hist.size())
            {
                broken[hist.front()] = true;
                hist.pop();
            }
        }
        else 
        {
            hist.emplace(index);
        }
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
