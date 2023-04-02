#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int a, b;

    cin >> a >> b;

    if((a + b)&1)
        cout << "Lucas" << "\n";
    else
        cout << "Pedro" << "\n";
}