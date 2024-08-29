#include <bits/stdc++.h>

using namespace std;

auto solve()
{
    int t, d, m;
    cin >> t >> d >> m;

    vector<int> vs(m);
    for(auto &x : vs)
        cin >> x;

    if(vs.empty())
        return t <= d;

    int last = 0;
    for(auto x : vs)
    {
        if(x - last  >= t)
            return true;

        last = x;
    }

    return d - last >= t; 
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
        cout << (solve() ? "Y" : "N") << "\n";
    }
}
