#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int a, b, c;

    cin >> a >> b >> c;

    vector<int> bells;

    bells.push_back(a);
    bells.push_back(b);
    bells.push_back(c);

    sort(bells.begin(), bells.end());

    cout << bells[0] + bells[1] << endl;
    return 0;
}