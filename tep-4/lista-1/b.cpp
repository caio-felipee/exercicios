
#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

auto solve() {
    int n;
    string moves;
    cin >> n >> moves;

    unordered_map<char, ii> dir;
    dir['L'] = {-1, 0};
    dir['R'] = {1, 0};
    dir['U'] = {0, 1};
    dir['D'] = {0, -1};

    ii current = {0, 0}, goal = {1, 1};
    for(auto &c : moves)
    {
        current.first += dir[c].first; 
        current.second += dir[c].second;

        if (current == goal)
            return "YES";
    }

    return "NO";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
        cout << solve() << "\n";

    return 0;
}
