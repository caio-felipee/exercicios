#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define all(x) x.begin(), x.end()

void solve() {
    int n, d, a, b;
    cin >> n >> d;

    vector<set<int>> dance(n);
    for(int i = 0; i < d; i++) {
        cin >> a >> b;
        dance[a].insert(b);
        dance[b].insert(a);
    }

    vi dist(n, 3000);
    dist[0] = 0;

    queue<int> q;
    q.emplace(0);

    while(not q.empty()) {
        int f = q.front();
        q.pop();

        for(int x : dance[f]) {
            if(dist[x] == 3000) {
                dist[x] = dist[f] + 1;
                q.emplace(x);
            }
        }
    }

    for(int i = 1; i < n; i++)
        cout << dist[i] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    cin >> t;

    while (t--) {
        solve();

        if(t > 0)
            cout << "\n";
    }

    return 0;
}