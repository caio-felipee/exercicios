#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n, k, step = 0;
    cin >> n >> k;

    vector<ll> teleporter(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> teleporter[i];
    }

    ll s = 1;
    vector<ll> vs;
    vector<bool> visited(n + 1, false);
    while(true) {
        vs.push_back(s);

        if(visited[s])
            break;

        visited[s] = true;
        s = teleporter[s];
        step++;

        if(step == k) {
            cout << s << "\n";
            return 0;
        }

    }

    // for(auto &x : vs)
    //     cout << x << " ";
    // cout << "\n";

    ll i = 0;
    while(vs[i] != s)
        i++;
    
    vector<ll> cycle(vs.begin() + i, vs.end());

    // for(auto &x : cycle)
    //     cout << x << " ";
    // cout << "\n";

    if(i)
        i--;

    k -= i;
    k %= (ll)cycle.size();

    // cout << k << " " << i << "\n";
 
    cout << cycle[k ? k + 1 : k] << "\n";
}