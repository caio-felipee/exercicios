
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using ii = pair<int, int>;
using pll = pair<ll, ll>;

template<typename T>
struct Point {
    T x, y;

    Point(T xv = 0, T yv = 0) : x(xv), y(yv) {}
};

template<typename T>
struct Line {
    T a, b, c;

    Line(const Point<T>& P, const Point<T>& Q)
        : a(P.y - Q.y), b (Q.x - P.x), c(P.x * Q.y - Q.x * P.y)
    {
    }

    bool contains(const Point<T>& P)
    {
        return a*P.x + b*P.y + c == 0;
    }
};

auto solve() {
    int n;
    cin >> n;

    vector<Point<int>> vs(n);
    for(int i = 0; i < n; i++)
        cin >> vs[i].x >> vs[i].y;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < n; k++)
            {
                if(i == j or i == k or j == k)
                    continue;

                Line<int> line(vs[i], vs[j]);

                if(line.contains(vs[k]))
                    return "Yes";
            }
        }
    }

    return "No";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;

    while(t--)
        cout << solve() << "\n";

    return 0;
}
