#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
using edge = tuple<int, int, int>;
using vi = vector<int>;
using vii = vector<ii>;

const int MAX { 100010 }, oo { 1000000010 };
vector<ii> adj[MAX];
bitset<MAX> processed;

pair<vector<int>, vector<ii>> dijkstra(int s, int N)
{
    vector<int> dist(N + 1, oo);
    vector<ii> pred(N + 1, { oo, oo });
    dist[s] = 0;
    pred[s] = { s, 0 };

    processed.reset();

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.emplace(0, s);

    while (not pq.empty())
    {
        ii du = pq.top();
        int d = du.first, u = du.second;
        pq.pop();

        if (processed[u])
            continue;

        processed[u] = true;

        for (ii vw : adj[u])
        {
            int v = vw.first, w = vw.second;
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pred[v] = { u, w };
                pq.emplace(dist[v], v);
            }
        }
    }

    return { dist, pred };
}

void solve() {
    int n;
    cin >> n;

    for(int i = 2; i <= n; i++) {
        for(int j = 1; j < i; j++) {
            string s;
            cin >> s;

            if(s == "x")
                continue;
            
            int v = stoi(s);
            adj[i].emplace_back(j, v);
            adj[j].emplace_back(i, v);
        }
    }

    pair<vector<int>, vector<ii>> dj = dijkstra(1, n);

    cout << *max_element(dj.first.begin() + 1, dj.first.end()) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;

    while(t--) {
        solve();
    }
}