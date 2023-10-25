#include <bits/stdc++.h>

using namespace std;
using edge = pair<int, int>;

const int MAX { 100010 }; 
int dfs_num[MAX], dfs_low[MAX];

int dfs_articulation_points(int u, int p, int& next, set<int>& points, vector<vector<int>> &adj)
{
    int children = 0;
    dfs_low[u] = dfs_num[u] = next++;

    for (auto v : adj[u])
        if (not dfs_num[v]) {
            ++children; 

            dfs_articulation_points(v, u, next, points, adj);

            if (dfs_low[v] >= dfs_num[u])
                points.insert(u);

            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (v != p)
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);

    return children;
}

set<int> articulation_points(int N, vector<vector<int>> &adj)
{
    memset(dfs_num, 0, (N + 1)*sizeof(int));
    memset(dfs_low, 0, (N + 1)*sizeof(int));

    set<int> points;

    for (int u = 1, next = 1; u <= N; ++u)
        if (not dfs_num[u])
        {
            auto children = dfs_articulation_points(u, u, next, points, adj);

            if (children == 1)
                points.erase(u);
        }
    
    return points;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while(cin >> n and n > 0) {
        vector<vector<int>> adj(n + 1);
        string st;
        getline(cin, st);
        while(getline(cin, st)) {
            stringstream s(st);
            int a, b;
            
            s >> a;
            while(a > 0 and s >> b) {
                adj[a].emplace_back(b);
                adj[b].emplace_back(a);
            }

            if(a == 0)
                break;
        }

        set<int> art = articulation_points(n, adj);

        cout << art.size() << "\n";
    }
} 
