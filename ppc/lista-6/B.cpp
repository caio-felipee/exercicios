#include <bits/stdc++.h>

using namespace std;

int main(void) {
    string l;

    cin >> l;

    int ans = -1, i = l.size();

    while(--i > 1) {
        if(ans >= 0) break;
        if(i&1) continue;

        int k = 0, j = i / 2;

        while(l[k++] == l[j++]) {
            if(j >= i) {
                ans = i;
                break;
            }
        }
    }

    cout << ans << endl;
    return 0;
}