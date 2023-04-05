#include <bits/stdc++.h>

// Para chegar na resolução sem força bruta, estudei o upsolving:
// https://qr.ae/prEQE0

using namespace std;

int main(void) {
    long long int l, r;

    cin >> l >> r;

    long long int x = l ^ r;
    long long int ans = 1;

    while(ans <= x)
        ans = ans << 1;
    
    cout << ans - 1 << endl;
}