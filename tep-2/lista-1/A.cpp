#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int a, b, c, d;

    cin >> a >> b >> c >> d;

    if((abs(a - b) <= d && abs(b - c) <= d) || abs(a - c) <= d)
        cout << "Yes";
    else
        cout << "No";
    
    cout << "\n";
}