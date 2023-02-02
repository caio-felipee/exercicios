#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int x1, y1, x2, y2;

    cin >> x1 >> y1 >> x2 >> y2;

    if(x1 > y2 || x2 > y1)
        cout << 0 << "\n";
    else
        cout << min(y1, y2) - max(x1, x2) << "\n";
    
    return 0;
}