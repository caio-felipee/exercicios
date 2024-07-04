#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
    int N, Q, t, ans = 0;
    cin >> Q >> N;

    priority_queue<ii, vector<ii>, greater<>> pq;
    unordered_map<int, int> index;
    for(int i = 0; i < N; i++) {
        cin >> t;
        
        ans += not index.count(t);
        pq.emplace(i, t);
        index[t] = i;
        
        while(index.size() > Q) {
            auto [ind, value] = pq.top();
            pq.pop();

            if(not index.count(value) or index[value] > ind)
                continue;
            
            index.extract(value);
        }
    }

    cout << ans << "\n";
}
