#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int N, tmpage;
    string tmpblood;

    set<pair<int, string>> profiles;

    cin >> N;

    while(N--) {
        cin >> tmpage >> tmpblood;

        profiles.insert({ tmpage, tmpblood });
    }

    cout << profiles.size() << "\n";
    return 0;
}