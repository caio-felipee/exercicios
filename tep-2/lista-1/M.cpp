#include <bits/stdc++.h>

using namespace std;

int main(void) {
    long long int n, k;

    cin >> n >> k;

    long long int h = 0;

    while(k) {
        if(k < n) {
            h++;
            break;
        }

        h += floor(max(n, k) / min(n, k));
        k = max(n, k) % min(n, k);
    }

    cout << h << "\n";
}
