#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n, r, a, b;

    cin >> n >> r;

    vector<int> profiles(n, 0);

    for(int i = 0; i < r; i++) {
        cin >> a >> b;

        profiles[--a]++;
        profiles[--b]++;
    }

    int relationships = 0;

    for(auto x : profiles)
        relationships += (n - 1 - x);

    cout << relationships / 2 << "\n";

}