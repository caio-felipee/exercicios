#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define all(x) x.begin(), x.end()
#define vin(vt) for (auto &e : vt) cin >> e
#define LSOne(S) ((S) & -(S))
#define MSOne(S) (1ull << (63 - __builtin_clzll(S)))

void get_composites(int n, unordered_set<int> &composites) {
    bool is_prime[n + 1];

    memset(is_prime, true, sizeof(is_prime));

    for(int i = 2; i * i <= n; i++) {
        if(is_prime[i]) {
            for(int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
                composites.insert(j);
            }
        }
    }
}

auto solve() {
    int n;

    cin >> n;

    unordered_set<int> composites;
    
    get_composites(n, composites);

    for(auto x : composites) {
        int y = n - x;

        if(composites.find(y) != composites.end()) {
            cout << min(x, y) << " " << max(x, y) << "\n";
            return;
        }
    }
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