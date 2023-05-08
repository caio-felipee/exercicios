#include <bits/stdc++.h>

using namespace std;

long long value[50005] = {0};

long long f(long long x) {
    if(x == 1 and not value[x])
        value[x] = 1ll;

    else if(not value[x])
        value[x] = f(x - 1) + (x*x*x);

    return value[x];
}

int main(void) {
    long long x;

    while(cin >> x && !cin.eof())
        cout << f(x) << "\n";
}