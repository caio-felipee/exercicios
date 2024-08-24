
#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()

using ll = long long;

auto solve()
{
    ll n, t;
    cin >> n >> t;

    string s;
    cin >> s;

    vector<ll> ant[2];
    for(ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;

        ant[s[i] - '0'].emplace_back(x);
    }

    sort(all(ant[1]));

    ll ans = 0;
    for(auto x : ant[0])
    {
        auto l = lower_bound(all(ant[1]), x - (t << 1LL));
        auto r = lower_bound(all(ant[1]), x); 
        
        ans += r - l;
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
