#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int x, a, b;

    cin >> x >> a >> b;

    if(x + 1 >= b - a && a - b >= 0) cout << "delicious" << "\n";
    else if(x + 1 > b - a) cout << "safe" << "\n";
    else cout << "dangerous" << "\n";
}