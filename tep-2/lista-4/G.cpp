#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define all(x) x.begin(), x.end()
#define vin(vt) for (auto &e : vt) cin >> e
#define LSOne(S) ((S) & -(S))

double fac[((int)10e7)+1] = {0};

void get_fac() {
    for(int i = 1; i <= 10e7; i++) {
        fac[i] = log10(i) + fac[i - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    cin >> t;

    get_fac();
    int n;

    while (t--) {
        cin >> n;

        cout << (int)fac[n] + 1 << "\n";
    }

    return 0;
}