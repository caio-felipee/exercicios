#include <bits/stdc++.h>

using namespace std;

map<long int, long int> r;

void f(long int *x) {
    if((*x)&1)
        *x = (3 * (*x)) + 1;
    else
        *x /= 2;
}

int main(void) {
    long int a, b;

    while(cin >> a >> b && (a || b)) {
        if(a > b)
            swap(a, b);
        
        pair<long int, long int> best = {0, 0};

        for(long int i = a; i <= b; i++) {
            long int tmp = i, times = 0;            

            do {
                if(r.find(tmp) == r.end()) {
                    times++;
                    f(&tmp);
                }

                else {
                    times += r[tmp];
                    break;
                }
            }
            while(tmp != 1);

            r[i] = times;

            if(times > best.second) {
                best = { i, times };
            }
        }

        cout << "Between " << a << " and " << b << ", " << best.first << " generates the longest sequence of " << best.second << " values.\n";
    }
}
