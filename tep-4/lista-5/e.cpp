#include <bits/stdc++.h>

using namespace std;

auto solve()
{
    int xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;

    int n, a, b;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        
        bool check = (a >= xa and a <= xb) and (b >= ya and b <= yb);
        cout << (check ? "Yes" : "No") << "\n";
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    for(int i = 1; i <= t; i++)
    {
        cout << "Case " << i << ":\n";
        solve();
    }

    return 0;
}
