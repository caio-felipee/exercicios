#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int a, b;

    while(cin >> a >> b and not cin.eof()) {
        int tmp;

        tmp = a/b;

        cout << "[" << tmp << ";";

        a = a - tmp * b;
        
        swap(a, b);

        tmp = a / b;

        cout << tmp;

        a = a - tmp * b;

        while(a != 0) {
            swap(a, b);

            tmp = a / b;

            cout << "," << tmp;

            a = a - tmp * b;
        }

        cout << "]\n";
    }
}