#include <bits/stdc++.h>

using namespace std;

int main() {
    int Q, N, t, ans = 0;
    cin >> Q >> N;

    queue<int> q;
    unordered_set<int> vs;
    for(int i = 0; i < N; i++) {
        cin >> t;
        
        if(not vs.count(t)) {
            ans++;
            q.emplace(t);
            vs.emplace(t);
        }

        while(vs.size() > Q) {
            vs.extract(q.front());
            q.pop();
        }
    }

    cout << ans << "\n";
}
