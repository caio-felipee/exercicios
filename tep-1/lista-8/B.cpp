#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int a;

    cin >> a;

    int power = log2(a), ans = 1;

    for(int i = 0; i < power; i++)
        ans *= 2; // avoiding pow function
    
    cout << ans << "\n";
    return 0;
}