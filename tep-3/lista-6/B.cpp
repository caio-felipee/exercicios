#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define all(x) x.begin(), x.end()
#define vin(vt) for (auto &e : vt) cin >> e

auto solve() {
    int n, t;
    cin >> n;

    vi graph(n + 1, -1);
    for(int i = 1; i <= n; i++) {
        cin >> t;
        graph[i] = t;    
    } 

    int ans = 0, hst = 0;
    for(int i = 1; i <= n; i++) {
        int curr = i;
        hst = 0;
        while(curr != -1) {
            hst++;
            curr = graph[curr];
        }

        ans = max(hst, ans);
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}