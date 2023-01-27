#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int N, X = 1;

    while(cin >> N && N) {
        vector<pair<int, int>> soldier;

        int B, J;
        int ans = 0, sum = 0;

        for(int i = 0; i < N; i++) {
            cin >> B >> J;

            soldier.push_back({ B, J });
        }
        
        sort(soldier.begin(), soldier.end(), [](const pair<int, int> &a, const pair<int, int> &b) { return a.second > b.second; });

        for(int i = 0; i < N; i++) {
            sum += soldier[i].first;
            ans = max(ans, soldier[i].second + sum);
        }

        cout << "Case " << X++ << ": " << ans << "\n";
    }

    return 0;
}