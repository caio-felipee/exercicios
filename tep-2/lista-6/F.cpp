#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define all(x) x.begin(), x.end()
#define vin(vt) for (auto &e : vt) cin >> e
#define LSOne(S) ((S) & -(S))
#define MSOne(S) (1ull << (63 - __builtin_clzll(S)))

void get_primes(int n, set<int> &primes) {
    bool is_prime[n + 10];

    memset(is_prime, true, sizeof(is_prime));

    for(long long i = 2; i <= n; i++) {
        if(is_prime[i]) {
            primes.insert(i);

            for(long long j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

void solve() {
    int m = 1000000;

    set<int> primes;

    get_primes(m, primes);

    primes.erase(2); // Remove the only even prime number

    int n;

    while(cin >> n and n) {
        bool found = false;

        for(int x : primes) {
            int y = n - x;

            if(x >= n)
                break;
            
            if(primes.find(y) != primes.end()) {
                cout << n << " = " << x << " + " << y << "\n";
                found = true;
                break;
            }
        }

        if(not found)
            cout << "Goldbach's conjecture is wrong." << "\n"; 
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}