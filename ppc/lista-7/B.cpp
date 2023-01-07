#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int N, K, t, ans = 0;
    vector<int> l;

    cin >> N >> K;

    while(N--) {
        cin >> t;

        l.push_back(t);
    }
    
    sort(l.begin(), l.end(), greater<int>());

    while(K--) 
        ans += l[K];
    
    cout << ans << endl;
    return 0;
}