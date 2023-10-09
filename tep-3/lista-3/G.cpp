#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define all(x) x.begin(), x.end()
#define vin(vt) for (auto &e : vt) cin >> e

bool dfs(vector<vi> &graph, vi &color, int source) {
    stack<int> s;
    s.emplace(source);
    color[source] = 1;
    while(not s.empty()) {
        int t = s.top();
        s.pop();

        for(auto &x : graph[t]) {
            if(not color[x]) {
                color[x] = 3 - color[t];

                s.emplace(x);
            }
            else if(color[x] == color[t]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;

    while(cin >> n and n) {
        int l, a, b;
        cin >> l;

        vector<vi> graph(n);
        for(int i = 0; i < l; i++) {
            cin >> a >> b;
            graph[a].push_back(b); 
        }

        vi color(n, 0);
        cout << (dfs(graph, color, 1) ? "BICOLORABLE." : "NOT BICOLORABLE.") << "\n";
    }     
}