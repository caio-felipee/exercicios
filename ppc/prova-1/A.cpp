#include <bits/stdc++.h>

using namespace std;

int main(void) {
    set<int> set;
    int num, buf;

    cin >> num;

    while(num--) {
        cin >> buf;

        set.insert(buf);
    }

    cout << set.size() << endl;
    return 0;
}