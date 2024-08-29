
// caio-felipee
//

#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;

int floyd(int n, vector<vi> &dist)
{
    int ans = 0;
    vector<vector<int>> check(n, vector<int>(n));
    for(int k = 0; k < n; k++)
    {
        for(int u = 0; u < n; u++)
        {
            for(int v = 0; v < n; v++)
            {
                if(dist[u][v] >= dist[u][k] + dist[k][v] and u != v and u != k and k != v)
                {
                    int dst = dist[u][k] + dist[k][v];
                    if(dist[u][v] > dst)
                        return -1;

                    dist[u][v] = dst;
                    ans += !check[u][v]++;
                }
            }
        }
    }

    return ans;
}

auto solve()
{
    int n;
    cin >> n;

    vector<vi> graph(n, vi(n));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    auto ans = floyd(n, graph);
    cout << (ans > 0 ? ans / 2 : ans) << "\n";
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
