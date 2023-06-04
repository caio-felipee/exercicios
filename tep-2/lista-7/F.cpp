#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

void get_primes(int n, vi &primes) {
    bool is_prime[n + 1];

    memset(is_prime, true, sizeof(is_prime));

    for(ll i = 2; i <= n; i++) {
        if(is_prime[i]) {
            primes.push_back(i);

            for(ll p = i * i; p <= n; p += i) {
                is_prime[p] = false;
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vi primes;

    get_primes(1000000, primes);

    int n;

    while(cin >> n and n) {
        int ans = 0;
        
        for(int prime : primes) {
            if(prime > n)
                break;
            
            if(n % prime == 0) {
                ans++;
            }
        }

        cout << n << " : " << ans << "\n";
    }
}