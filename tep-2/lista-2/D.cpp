#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n, k;

    while(cin >> n >> k and not cin.eof()) {
        int sum = n;

        while(n >= k) {
            sum += n / k;
            n = (n / k) + (n % k);
        }

        cout << sum << "\n";
    }
}