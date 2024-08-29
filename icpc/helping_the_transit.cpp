// caio-felipee
//

#include <bits/stdc++.h>

using namespace std;

constexpr int MAX { 10'010 };

vector<int> adj[MAX], rev[MAX];
bitset<MAX> visited;

void dfs(int u, vector<int>& order)
{
    if (visited[u])
        return;

    visited[u] = true;

    for (auto v : adj[u])
        dfs(v, order);

    order.emplace_back(u);
}

vector<int> dfs_order(int N)
{
    vector<int> order;

    for (int u = 1; u <= N; ++u)
        dfs(u, order);

    return order;
}

void dfs_cc(int u, vector<int>& cc)
{
    if (visited[u])
        return;

    visited[u] = true;
    cc.emplace_back(u);

    for (auto v : rev[u])
        dfs_cc(v, cc);
}

vector<vector<int>> kosaraju(int N) {
    auto order = dfs_order(N);
    reverse(order.begin(), order.end());

    for (int u = 1; u <= N; ++u)
        for (auto v : adj[u])
            rev[v].emplace_back(u);

    vector<vector<int>> cs;
    visited.reset();

    for (auto u : order) {
        if (visited[u])
            continue;

        cs.emplace_back(vector<int>());
        dfs_cc(u, cs.back());
    }
        
    return cs;
}

auto solve()
{
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].emplace_back(b);
    }

    auto res = kosaraju(n);
    vector<int> real(n + 1);
    int pos = 0;
    for(auto vs : res)
    {
        for(auto x : vs)
        {
            real[x] = pos;  
        }
        pos++;
    }

    if(pos == 1)
    {
        cout << 0 << "\n";
        return;
    }

    vector<pair<int, int>> graph(pos);
    for(int i = 1; i <= n; i++)
    {
        for(auto x : adj[i])
        {
            if(real[x] != real[i])
            {
                auto &[in_x, out_x] = graph[real[x]];
                auto &[in_i, out_i] = graph[real[i]];

                out_i++; 
                in_x++;
            }
        }
    }
    
    int not_in = 0, not_out = 0;
    for(int i = 0; i < pos; i++)
    {
        auto &[in, out] = graph[i]; 

        not_in += !in;
        not_out += !out;
    }

    cout << max(not_in, not_out) << "\n";
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
        solve();
    }
}
